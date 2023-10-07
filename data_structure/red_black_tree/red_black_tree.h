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
        RBT() : data(0), left(NULL), right(NULL), parent(NULL){};
        RBT(data) : data(data), left(NULL), right(NULL), parent(NULL){};
        RBT* search(RBT*, int);
        void print(RBT*);

        RBT* insert(RBT*, int);
        RBT* rotateLeft(RBT*);
        RBT* rotateRight(RBT*);
};