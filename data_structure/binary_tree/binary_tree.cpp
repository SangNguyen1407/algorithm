#include <iostream>
#include "./binary_tree.h"

using namespace std;

NODE *initialize_new_node(int data){
    NODE *node = (NODE *) malloc(sizeof(NODE *));
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

NODE *Btree::get_root_node(){
    return root;
}

NODE *Btree::update_root_node(NODE *node){
    root = node;

    return root;
}
/*
             1
            / \
            0   8
                / \
    delete ->  3   9        
                \
                5   <= deletedNode_parent
                /
                5  <= deletedNode

            1
           / \
          0   8
             / \
            5   9        
             \
              5   
             /
            3  <= deleted
*/

NODE *Btree::removeNode(NODE *node, int data){
    if(node == NULL){
        return node;
    }

    if(node->data > data){
        node->left_child = removeNode(node->left_child, data);
        return node;
    }
    else if(node->data < data){
        node->right_child = removeNode(node->right_child, data);
        return node;
    }

    // node->data = data
    // Is a leaf
    if (node->left_child == NULL){
        NODE *temp = node->right_child;
        delete(node);

        return (temp);
    }
    else  if (node->right_child == NULL){
        NODE *temp = node->left_child;
        delete(node);

        return (temp);
    }
    else{
        // node with 2 child (lelf and right)
        NODE *deletedNode_parent = node;
        NODE *deletedNode        = node->right_child;
        // the last left leaf_node 
        while (deletedNode->left_child != NULL){
            deletedNode_parent = deletedNode;
            deletedNode = deletedNode->left_child;
        }
        //change the last left leave node to remove_node
        if(deletedNode_parent != node){
            deletedNode_parent->left_child = deletedNode->right_child;
        }
        else{
            deletedNode_parent->right_child = deletedNode->right_child;
        }

        node->data = deletedNode->data;

        delete deletedNode;
        return node;
    }

}

NODE* Btree::insertBtree( NODE *node, int data){

    if(node == NULL){
        NODE *new_node = initialize_new_node(data);
        node = new_node;
        return node;
    }

    if (node->data > data){
        if ( node->left_child != NULL){
            insertBtree(node->left_child, data);
        }
        else{
            NODE *new_node = initialize_new_node(data);
             node->left_child = new_node;
        }
    }
    else{
        if ( node->right_child != NULL){
            insertBtree(node->right_child, data);
        }
        else{
            NODE *new_node = initialize_new_node(data);
             node->right_child = new_node;
        }
    }

    return node;
}

int Btree::search( NODE *node, int data){
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
int Btree::printBtree(NODE* node) {

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
    NODE *root = tree.get_root_node();

    for (int i = 0; i< arr_size; i++ ){
        root = tree.insertBtree(root, arr[i]);
    }
    tree.update_root_node( root );
    tree.printBtree( root );

    cout << endl;
    tree.printBtree( tree.get_root_node() );

    cout << endl;
    cout << "search 5: ";
    cout << tree.search(root, 5) << endl;
    
    cout << endl;
    cout << "search 2: ";
    cout << tree.search(root, 2) << endl;

    cout << endl;
    cout << "search 0: ";
    cout << tree.search(root, 0) << endl;

    cout << endl;
    cout << "search 4: ";
    cout << tree.search(root, 4) << endl;


    cout << "remove 3: " << endl;
    tree.removeNode(root, 3);
    tree.update_root_node( root );
    tree.printBtree( root );
    
    return 1;
}

