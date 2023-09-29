#include <iostream>
#include "./binary_tree.h"

using namespace std;

node* Btree::insertBtree( node* tree, int data){

    struct node *node = (struct node *) malloc(sizeof(struct node *));
    node->data = data;
    node->left_child = NULL;
    node->right_child = NULL;

    if(tree == NULL){cout << "2. " << endl;
        tree = node;
        return tree;
    }

    if ( tree->left_child == NULL && tree->right_child == NULL ){
        if (tree->data < data){
            tree->left_child = node;
        }
        else{
            tree->right_child = node;
        }
        return tree;
    }

    if (tree->data < data){
        insertBtree(tree->left_child, data);
    }
    else{
        insertBtree(tree->right_child, data);
    }

    return tree;

}

int Btree::printBtree(node* node) {

    if(node == nullptr) { cout << "1. " << endl;
        return 0;
    }

    if( node->left_child  == nullptr &&  node->right_child == nullptr )
    {
        cout << node->data << " ";
        return 0;
    }

    if (node->left_child != nullptr){
        printBtree( node->left_child );
    }

    if (node->right_child != nullptr){
        printBtree( node->right_child );
    }

    return 0;
}

int main (){
    Btree tree;
//    RBnode *node = tree.root;
    tree.insertBtree(tree.root, 1);
    tree.insertBtree(tree.root, 2);
    tree.insertBtree(tree.root, 3);

    tree.printBtree( tree.root );
    return 1;
}

