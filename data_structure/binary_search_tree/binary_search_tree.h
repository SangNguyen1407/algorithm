/*
https://www.geeksforgeeks.org/insertion-in-binary-search-tree/?ref=lbp
*/
#include <iostream>


class BST {
    private:
        int data;
        BST *left;
        BST *right;
    public:    
        BST() : data(0), left(NULL), right(NULL){};

        BST(int value) : data(value), left(NULL), right(NULL){};
        ~BST(){};
        BST* insertNode(BST*, int);
        BST* search(BST*, int);
        void print(BST*);
};