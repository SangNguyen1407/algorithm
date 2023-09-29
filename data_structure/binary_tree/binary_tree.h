
struct node {
    node *left_child;
    node *right_child;
    int data;

};

class Btree {
    private:    
        node *root;

    public:
        Btree();
        ~Btree();

        node* get_root_node();
        node* insertBtree(node *, int );
        int search(node *, int);
        int printBtree( node* );
};