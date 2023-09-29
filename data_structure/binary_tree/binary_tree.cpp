#include <iostream>
#include "./binary_tree.h"

using namespace std;

struct node *new_node(int data){
    struct node *node = (struct node *) malloc(sizeof(struct node *));
    node->data = data;
    node->left_child  = NULL;
    node->right_child = NULL;

    return node;
}

Btree::Btree(){
    root = NULL;
}

Btree::~Btree(){
}

node *Btree::get_root_node(){
    return root;
}

node* Btree::insertBtree( node *tree, int data){

    if(tree == NULL){
        struct node *node = new_node(data);
        tree = node;
        return tree;
    }

    if (tree->data > data){
        if ( tree->left_child != NULL){
            insertBtree(tree->left_child, data);
        }
        else{
            struct node *node = new_node(data);
             tree->left_child = node;
        }
    }
    else{
        if ( tree->right_child != NULL){
            insertBtree(tree->right_child, data);
        }
        else{
            struct node *node = new_node(data);
             tree->right_child = node;
        }
    }

    return tree;

}

int Btree::search( node *node, int data){
    if(node == NULL){
        return 0;
    }

    if( node->data == data )
    {
        return 1;
    }
    else if (node->data > data){
        return search(node->left_child, data);
    }
    else{
        return search(node->right_child, data);
    }


}
int Btree::printBtree(node* node) {

    if(node == NULL) {
        return 0;
    }

    if( node->left_child  == NULL &&  node->right_child == NULL )
    {
        cout << node->data << " ";
        return 0;
    }

    if (node->left_child != NULL){
        printBtree( node->left_child );
    }

    if (node->right_child != NULL){
        printBtree( node->right_child );
    }
    cout << node->data << " ";
    return 0;
}

int main (){
    Btree tree;
    int arr[] = {1,8,3,5,9,5,0};
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
    node *root = tree.get_root_node();

    for (int i = 0; i< arr_size; i++ ){
        root = tree.insertBtree(root, arr[i]);
    }
    tree.printBtree( root );

    cout << endl;
    cout << "search 5: ";
    cout << tree.search(root, 5) << endl;
    
    cout << endl;
    cout << "search 2: ";
    cout << tree.search(root, 2) << endl;

    return 1;
}

