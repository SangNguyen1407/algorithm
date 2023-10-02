#include <iostream>
using namespace std;

BST::BST() : data(0), left_child(NULL), right_child(NULL)
{
}

BST::BST(int value)
{
    data = value;
    left_child = NULL;
    right_child = NULL;
}

// Insert function definition.
BST* BST::insertNode(BST* root, int value)
{
    if (!root){
        return new BST(value);
    }

    if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    else if (value < root->data) {
        root->left = insertNode(root->left, value);
    }

    return root;
}

int main (){
    
}