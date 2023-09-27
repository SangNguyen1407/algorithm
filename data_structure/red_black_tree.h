
enum color_t { BLACK, RED };

struct RBnode {
    RBnode *parent;
    RBnode *left_child;
    RBnode *right_child;

    enum color_t color;
    int data;

    RBnode (int x) : data(x), left_child(NULL),  right_child(NULL){}
};

class RBtree {
    private:
        RBnode *root;

    public:
        RBnode* RotateDirRoot( RBtree* , RBtree*, int );
        RBnode* RotateRight( RBtree* , RBtree* );
        RBnode* RotateLeft( RBtree* , RBtree* );
        
        void insertRP(int );
        int printRBNode( );
        int detroyRBNode( );
};