
struct node {
    node *left_child;
    node *right_child;
    int data;

};

class Btree {
    public:
        node *root;
        
        node* insertBtree(node*, int );
        int printBtree( node* );
};