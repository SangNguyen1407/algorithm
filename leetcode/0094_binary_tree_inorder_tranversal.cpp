/*  
    Given the root of a binary tree, return the inorder traversal of its nodes' values.
    
    Input: root = [1,null,2,3]
    Output: [1,3,2]

    Input: root = []
    Output: []

    Input: root = [1]
    Output: [1]
*/

#include <iostream>
#include <string>
#include <vector>

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
    vector<int> rst;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL){
            return rst;
        }

        inorderTraversal(root->left);
        
        rst.push_back(root->val);

        inorderTraversal(root->right);

        return rst;
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

    int arr1[] = {1,2,2,3};
    int pos = 0;
    int len = sizeof(arr1) / sizeof(arr1[0]);

    TreeNode *node = new TreeNode(arr1[0]);
    node->left     = new TreeNode(arr1[1]);
    node->right    = NULL;

    node->left->left   = new TreeNode(arr1[2]);
    node->left->right  = new TreeNode(arr1[3]);
//    node->right->left  = new TreeNode(arr1[5]); 

    sol.inorderTraversal(node);

    cout << "result: ";
    for (pos = 0; pos < len; pos++){
        cout <<  sol.rst[pos] << "  " ;
    } 

    return 0;
}