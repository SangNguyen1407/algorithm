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
        RBNode* search(RBNode*, int);
        void print(RBNode*);

        RBNode* insert( RBNode*, int );
        RBNode* rotateLeft( RBNode* );
        RBNode* rotateRight( RBNode* );
};