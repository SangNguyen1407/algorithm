#include <iostream>
#include "./red_black_tree.h"

using namespace std;

void RBtree::insertRP(int data){
    RBnode node(data);
    RBnode *tree;

    if (root == NULL){
        root = &node;
        return;
    }

    tree = root;

    do{
        if (tree->data < data){
            if (tree->left_child == NULL){
                tree->left_child = &node;
                break;
            }
            tree = tree->left_child;
        }
        else{
            if (tree->right_child == NULL){
                tree->right_child = &node;
                break;
            }
            tree = tree->right_child;
        }
    }while(tree != NULL);

}

int main (){
    RBtree tree;

    tree.insertRP(1);
    tree.insertRP(2);
    return 1;
}

