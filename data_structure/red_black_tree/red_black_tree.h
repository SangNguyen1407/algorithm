#include <iostream>

enum color_t {
    BLACK,
    RED
};

struct RBNode {
    RBNode *parent;
    RBNode *left;
    RBNode *right;
    int data;

    enum color_t color;
    RBNode(int data) : data(data),  
                       left(NULL),  
                       right(NULL), 
                       parent(NULL),  
                       color(RED) {};
    RBNode()         : data(0), 
                       left(NULL), 
                       right(NULL), 
                       parent(NULL),
                       color(RED) {};
};

class RBT {
    private:
        RBNode *root;
        bool ll; // Left-Left Rotation flag
        bool rr; // Right-Right Rotation flag
        bool lr; // Left-Right Rotation flag
        bool rl; // Right-Left Rotation flag

    public:
        RBT() : root(nullptr), ll(false), rr(false), lr(false), rl(false) {}
        RBNode* search(RBNode*, int);
        void print(RBNode*);
        void printTree();
        void insert( int );

        RBNode* insert_node_and_rotation( RBNode*, int );
        RBNode* rotateLeft( RBNode* );
        RBNode* rotateRight( RBNode* );
};