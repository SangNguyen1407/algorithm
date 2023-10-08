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

RBNode* search(RBNode* root, int data){
   if ( root == NULL || root->data == data ){
      return NULL;
   }

   if (root->data > data){
      return search(root->left, data);
   }
   else if (root->data < data){
      return search(root->right, data);
   }

   return ( root );
}

void RBT::print(RBNode* root){
    if (root == NULL){
        return;
    }

    print (root->left);
    cout << root->data << " ";
    print (root->right);
    
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
RBNode* RBT::rotateLeft(RBNode* root){
   RBNode* ri = root->right;
   RBNode* t3 = ri->left;

   ri->left      = root;
   root->right   = t3;
   root->parent  = ri;

   if (t3 != NULL){
      t3->parent = root;
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
RBNode* RBT::rotateRight(RBNode* root){
   RBNode* l  = root->left;
   RBNode* t3 = l->right;

   l->right      = root;
   root->right   = t3;
   root->parent  = l;

   if (t3 != NULL){
      t3->parent = root;
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
RBNode* RBT::insert(RBNode* root, int data){
   /* 1. Add node like binary tree
      2. Because of parent point, and return node can not input node 
         so return node with linked parent point to root
      3. RBT rule 4 (one red and 2 black child ) 
   */
   bool red_conflict = false; 

   if (root == NULL){
      return new RBNode(data);
   }
   else if (root->data > data){
      root->left         = insert(root->left, data);
      root->left->parent = root;
      if (root != this->root){
         if (root->color == RED && root->left->color == RED){
            red_conflict = true;
         }
      }
   }
   else{
      root->right         = insert(root->right, data);
      root->right->parent = root;
      if (root != this->root){
         if (root->color == RED && root->right->color == RED){
            red_conflict = true;
         }
      }
   }

   // rotation
   if ( ll ){
      root = rotateLeft( root );
      root->color       = BLACK;
      root->left->color = RED;
      ll = false;
   }
   else if ( rr ){
      root = rotateRight( root );
      root->color        = BLACK;
      root->right->color = RED;
      rr = false;
   } 
   else if ( rl ){
      root->right = rotateRight( root->right );
      root->right->parent = root;
      root = rotateLeft( root );
      root->color       = BLACK;
      root->left->color = RED;
      rl = false;
   }
   else if ( lr ){
      root->left = rotateLeft( root->left );
      root->left->parent = root;   
      root = rotateRight( root );
      root->color        = BLACK;
      root->right->color = RED;
      lr = false;
   }

   // 3. RBT rule 4 (one red and 2 black child ) 
   if ( red_conflict ){
      if ( root->parent->right == root ){
         
      }
   }
}

int main(){

}