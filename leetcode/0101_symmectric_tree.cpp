/*  
   Given the root of a binary tree, check whether it is a 
   mirror of itself (i.e., symmetric around its center). 
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

    bool isMirror(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL){
            return true;
        }

        if(left == NULL || right == NULL){
            return false;
        }

        return(left->val == right->val &&
                isMirror(left->left, right->right) && 
                isMirror(left->right, right->left)
            );
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};

int main (){

    Solution sol;
    int arr1[] = {1,2,2,3,4,4,3};
    int pos = 0;
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
        
    TreeNode *node = new TreeNode(arr1[0]);
    node->left     = new TreeNode(arr1[1]);
    node->right    = new TreeNode(arr1[2]);

    node->left->left   = new TreeNode(arr1[3]);
    node->left->right  = new TreeNode(arr1[4]);
    node->right->left  = new TreeNode(arr1[5]);
//    node->right->right = new TreeNode(arr1[6]);
    

    cout << "result: " << sol.isSymmetric(node) << endl ;

    return 0;
}