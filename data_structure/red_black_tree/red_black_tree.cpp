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

int main(){

}