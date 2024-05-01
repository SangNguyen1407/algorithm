/*  
    Given an integer n, return the number of structurally unique BST's (binary search trees) 
    which has exactly n nodes of unique values from 1 to n.
    
    Input: n = 3
    Output: 5

    Input: n = 1
    Output: 1



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

    int numTrees(int n) {
        int count[n + 1];

        count[0] = 1;
        count[1] = 1;

        for (int i = 2; i <= n; i++){
            count[i] = 0;
            for (int j = 0; j < i; j++){
                count[i] += count[j] * count[i - j - 1];
            }
        }

        return count[n];
    }
};


int main (){
    Solution sol;
    int num = sol.numTrees(19);

    cout << "the number of structurally unique BST's is " << num << endl;

    return 0;
}