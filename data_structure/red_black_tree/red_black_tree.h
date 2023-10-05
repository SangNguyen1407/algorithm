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
};

class RBT {
    private:
        RBNode root;

    public:    
        
};