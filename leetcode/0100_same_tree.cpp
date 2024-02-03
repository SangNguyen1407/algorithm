/*  
    Given two binary trees, write a function to check if they are equal or not.
    Two binary trees are considered equal if they are structurally identical and
    the nodes have the same value.
*/

#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (q == NULL && p == NULL ){
            return true;
        }
        else if (q == NULL ||  p == NULL ){
            return false;
        } 

        return (
            (p->val == q->val) && 
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right)
            );
    }
};


TreeNode* addNode(TreeNode* node, int value){
    if (node == NULL){
        return ( new TreeNode(value) );
    }

    return (node->val > 0) ? addNode(node->right, value) : addNode(node->left, value);
}

int main (){

    Solution sol;
    int arr1[] = {1,0,2};
    int arr2[] = {1,0,2};
    int pos = 0;
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
        
    TreeNode *node1 = NULL;
    TreeNode *node2 = NULL;

    for (pos = 0; pos < len1; pos++){
        node1 = addNode(node1, arr1[pos]); 
    }    

    for (pos = 0; pos < len1; pos++){
        node2 = addNode(node2, arr2[pos]); 
    } 

    cout << "result: " << sol.isSameTree(node1, node2) << endl ;

    return 0;
}


