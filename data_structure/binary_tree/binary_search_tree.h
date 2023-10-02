/*
https://www.geeksforgeeks.org/insertion-in-binary-search-tree/?ref=lbp
*/
#include <iostream>

typedef struct node {
    int data;
    node *left_child;
    node *right_child;
} NODE;


class BST {
    NODE* root;
    
    BST();
    BST(int value);
    ~BST();
    BST* insertNode(BST*, int);
    void inorder(BST*);
}