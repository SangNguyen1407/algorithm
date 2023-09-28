#include <iostream>
#include "./red_black_tree.h"

using namespace std;

RBnode* RBtree::insertRP( RBnode* tree, int data){
    RBnode node(data);

    if (tree == NULL){
        tree = &node;
        return tree;
    }

    if (tree->data < data){
        insertRP(tree->left_child, data);
    }
    else{
        insertRP(tree->right_child, data);
    }

    return tree;

}

int RBtree::printRBNode(RBnode* node) {

    if(node == nullptr) {
        return 0;
    }
 cout <<  "-1. " << endl;
    if( node->left_child  == nullptr &&  node->right_child == nullptr )
    {cout <<  "0. " << endl;
        cout << node->data << " ";
        return 0;
    }

    if (node->left_child != nullptr){
        cout <<  "1. " << endl;
        printRBNode( node->left_child );
    }

    if (node->right_child != nullptr){
        cout <<  "2. " << endl;
        printRBNode( node->right_child );
    }

    return 0;
}

int main (){
    RBtree tree;
//    RBnode *node = tree.root;

    tree.insertRP(tree.root, 1);
    tree.insertRP(tree.root, 2);
    tree.insertRP(tree.root, 3);

    tree.printRBNode( tree.root );
    return 1;
}

