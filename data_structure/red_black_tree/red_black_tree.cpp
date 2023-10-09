/*
A red-black tree T is a binary search tree having 
following five additional properties (invariants).

1. Every node in T is either red or black.
2. The root node of T is black.
3. Every NULL node is black. (NULL nodes are the 
   leaf nodes. They do not contain any keys. 
   When we search for a key that is not present 
   in the tree, we reach the NULL node.)
4. If a node is red, both of its children are black. 
   This means no two nodes on a path can be red nodes.
5. Every path from a root node to a NULL node has 
   the same number of black nodes.
*/

#include <iostream>
#include "./red_black_tree.h"

using namespace std;

RBNode* search(RBNode* node, int data){
   if ( node == NULL || node->data == data ){
      return NULL;
   }

   if (node->data > data){
      return search(node->left, data);
   }
   else if (node->data < data){
      return search(node->right, data);
   }

   return ( node );
}
void RBT::printTree(){
   print(root);
}

void RBT::print(RBNode* node){
    if (node == NULL){
        return;
    }
    cout << node->data << " " << endl;
    print (node->left);
    print (node->right);
    
}

/*
        Ro                      Ri
      /   \                   /   \
     L     Ri       ->       Ro    X
    / \   / \               / \   / \
   T1 T2 T3  X             L  T3 T4 T5 
            / \           / \
           T4 T5         T1 T2
*/
RBNode* RBT::rotateLeft(RBNode* node){
   RBNode* ri = node->right;
   RBNode* t3 = ri->left;

   ri->left      = node;
   node->right   = t3;
   node->parent  = ri;

   if (t3 != NULL){
      t3->parent = node;
   }
   return ri;

}

/*
        Ro                      L
      /   \                   /   \
     L     Ri       ->       X    Ro
    / \   / \               / \   / \
   X  T3 T4  T5            T1 T2 T3  Ri 
  / \                                / \
 T1 T2                              T4 T5

*/
RBNode* RBT::rotateRight(RBNode* node){
   RBNode* l  = node->left;
   RBNode* t3 = l->right;

   l->right      = node;
   node->left    = t3;
   node->parent  = l;

   if (t3 != NULL){
      t3->parent = node;
   }
   return l;
}

/*
   Ro(B)       ->  B(3)
                    \
                    R(21)

   B(3)       ->    B(21)
    \              /   \
     R(21)        R(3)  R(32)
      \
       R(32)

     B(21)       ->      B(21)
    /   \               /   \
   R(3)  R(32)         B(3)  R(32)
    \                   \
     R(15)               R(15)


*/
RBNode* RBT::insert_node_and_rotation(RBNode* node, int data){
   /* 1. Add node like binary tree
      2. Because of parent point, and return node can not input node 
         so return node with linked parent point to root
      3. RBT rule 4 (one red and 2 black child ) 
   */ 
   bool red_conflict = false; 
   if (node == NULL){
      return new RBNode(data);
   }
   else if (node->data > data){
      node->left         = insert_node_and_rotation(node->left, data);
      node->left->parent = node;
      if (node != this->root){
         if (node->color == RED && node->left->color == RED){
            red_conflict = true;
         }
      }
   }
   else{
      node->right         = insert_node_and_rotation(node->right, data);
      node->right->parent = node;
      if (node != this->root){
         if (node->color == RED && node->right->color == RED){
            red_conflict = true;
         }
      }
   }

   // rotation
   if ( ll ){
      node = rotateLeft( node );
      node->color       = BLACK;
      node->left->color = RED;
      ll = false;
   }
   else if ( rr ){
      node = rotateRight( node );
      node->color        = BLACK;
      node->right->color = RED;
      rr = false;
   } 
   else if ( rl ){
      node->right = rotateRight( node->right );
      node->right->parent = node;
      node = rotateLeft( node );
      node->color       = BLACK;
      node->left->color = RED;
      rl = false;
   } 
   else if ( lr ){
      node->left = rotateLeft( node->left );
      node->left->parent = node;   
      node = rotateRight( node );
      node->color        = BLACK;
      node->right->color = RED;
      lr = false;
   }

   // 3. RBT rule 4 (one red and 2 black child ) 
   if ( red_conflict ){
      if ( node->parent->right == node ){
         if ( node->parent->left == NULL || node->parent->left->color == BLACK ){
            if ( node->left == NULL || node->left->color == RED ){
               rl = true;
            }
            else if ( node->right == NULL || node->right->color == RED ){
               ll = true;
            }
         }
         else{
            node->parent->left->color = BLACK;
            node->color = BLACK;
            if (node->parent != this->root){
               node->parent->color = RED;
            }
         }
      }
      else{
         if ( node->parent->right == NULL || node->parent->right->color == BLACK ){
            if ( node->left == NULL || node->left->color == RED ){
               rr = true;
            }
            else if ( node->right == NULL || node->right->color == RED ){
               lr = true;
            }
         }
         else{
            node->parent->right->color = BLACK;
            node->color = BLACK;
            if (node->parent != this->root){
               node->parent->color = RED;
            }
         }         
      }

      red_conflict = false;
   }

   return node;
}

void RBT::insert(int data){
   if (root == NULL){
      root = new RBNode(data);
      root->color = BLACK;
   }
   else{
      root = insert_node_and_rotation(root, data);
   }
}

int main(){
   RBT tree;
   int arr[] = {1,8,3,5,9,0};
   int arr_size = sizeof(arr) / sizeof(arr[0]); 

   for (int i = 0; i < arr_size; i++){
      tree.insert(arr[i]);
   }

   tree.printTree();
}