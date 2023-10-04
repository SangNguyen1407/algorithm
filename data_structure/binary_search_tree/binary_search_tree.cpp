#include <iostream>
#include "./binary_search_tree.h"
using namespace std;

// Insert function definition.
BST* BST::insertNode(BST* root, int value)
{
    if (!root){
        return new BST(value);
    }

    if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    else if (value <= root->data) {
        root->left = insertNode(root->left, value);
    }

    return root;
}

BST* BST::search(BST* root, int data){
    if (root == NULL){
        return NULL;
    }

    if (root->data > data){
        return search(root->left, data);
    }
    else if (root->data < data){
        return search(root->right, data);
    }

    return ( (root->data == data)? root:NULL );
}

void BST::print(BST* root){
    if (root == NULL){
        return;
    }

    print (root->left);
    cout << root->data << " ";
    print (root->right);
    
}

int main (){
    BST bst;
    BST *root = NULL;
    int arr[] = {1,8,3,5,5,5,0};
    int arr_size = sizeof(arr) / sizeof(arr[0]);  

    root = bst.insertNode(root, arr[0]);
    for (int i = 1; i< arr_size; i++ ){
        bst.insertNode(root, arr[i]);
    }

    bst.print( root );
    return 0;
}