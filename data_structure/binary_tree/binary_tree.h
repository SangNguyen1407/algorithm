
#include <iostream>

typedef struct node {
    node *left_child;
    node *right_child;
    int data;

} NODE;

class Btree {
    private:    
        NODE *root;

    public:
        Btree();
        ~Btree();

        NODE* get_root_node();
        NODE* update_root_node(NODE * );

        int printBtree(NODE* );
        int search(NODE *, int);

        NODE* insertBtree(NODE *, int );
        NODE* removeNode(NODE *, int );
};