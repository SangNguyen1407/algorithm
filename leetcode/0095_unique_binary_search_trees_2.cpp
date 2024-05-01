/*  
    Given an integer n, return all the structurally unique BST's (binary search trees), 
    which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
    
    Input: n = 3
    Output: 
        [
            [1,null,2,null,3],
            [1,null,3,2],
            [2,1,3],
            [3,1,null,null,2],
            [3,2,null,1]
        ]
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
    void treePrint(TreeNode* root) {
        if(root == NULL){
            return;
        }

        treePrint(root->left);       
        treePrint(root->right);
        cout << root->val << " "; 

        return;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0){
            return {};
        }

        return generateTreesDFS(1, n);
    }

    vector<TreeNode*> generateTreesDFS(int start, int end) {
        vector<TreeNode*> subTree;
        if(start > end){
            subTree.push_back(NULL);
        }
        else{
            for (int i = start; i <= end; i++){
                vector<TreeNode*> leftSubTree = generateTreesDFS(start, i - 1);
                vector<TreeNode*> rightSubTree = generateTreesDFS(i + 1, end);
                for (int j = 0; j < leftSubTree.size(); j++){
                    for (int k = 0; k < rightSubTree.size(); k++){
                        TreeNode *node = new TreeNode(i);
                        node->left = leftSubTree[j];
                        node->right = rightSubTree[k];
                        subTree.push_back(node);
                    }

                }
            }
        }

        return subTree;
    }
};


int main (){
    Solution sol;
    vector<TreeNode*> result = sol.generateTrees(3);

    cout << "result: " << endl;
    for (int i = 0; i < result.size(); i++){
        sol.treePrint(result[i]);

        cout << endl;
    } 
    

    return 0;
}