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

RBT* search(RBT* root, int data){
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

void RBT::print(RBT* root){
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
RBT* RBT::rotateLeft(RBT* root){
   RBT* ri = root->right;
   RBT* t3 = ri->left;

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
RBT* RBT::rotateRight(RBT* root){
   RBT* l  = root->left;
   RBT* t3 = l->right;

   l->right      = root;
   root->right   = t3;
   root->parent  = l;

   if (t3 != NULL){
      t3->parent = root;
   }

   return ri;

}

int main(){

}