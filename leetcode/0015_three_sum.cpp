/*
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation: 
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not matter.
 * 
 * Example 2:
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 * 
 * Example 3:
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 * 
 */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int nodeEnd, theNextNode;
        vector<vector<int>> rst;

        for (int i = 0; i < size-2; i++)
        {
            nodeEnd = size - 1;
            theNextNode = i + 1;

            while (theNextNode < nodeEnd)
            {
                int sum = nums[i] + nums[theNextNode] + nums[nodeEnd];
                if (sum == 0)
                {
                    vector<int> vector_node;
                    int rst_size = rst.size();
                    int flag_isTheSameNode = 0;

                    // check the vector_mode and push_back the vector_back
                    if (rst_size != 0) 
                    {
                        for (int j = rst_size-1; j >= 0; j--)
                        {
                            // if the first value is different, break out
                            if ( rst.at(j).at(0) != nums[i] )
                            {
                                break;
                            }
                            else if( (rst.at(j).at(1) == nums[theNextNode]) 
                                     && (rst.at(j).at(2) == nums[nodeEnd]) )
                            {
                                flag_isTheSameNode = 1;
                                break;
                            } 
                        } 
                    }

                    if (!flag_isTheSameNode)
                    {
                        // create vector_node when push_back into "rst"
                        vector_node.push_back(nums[i]);
                        vector_node.push_back(nums[theNextNode]);
                        vector_node.push_back(nums[nodeEnd]);

                        // add new vector node
                        rst.push_back(vector_node);
                    }
                    theNextNode++;
                }
                else if (sum < 0)
                {
                    theNextNode++;
                }
                else
                {
                    nodeEnd--;
                }
            }
        }
        return rst; 
    }

    int printVector(vector<vector<int>> vect){
        for (int i = 0; i < vect.size(); i++)
        {
            for (int j = 0; j < vect[i].size(); j++)
            {
                cout << vect[i][j] << " ";
            }    
            cout << endl;
        }

        return 0;
    }
};

int main (){
    // Initializer list
    Solution s;
    std::vector< std::vector<int> > rst;

    vector<int> vector{-1, 0, 1, 2, -1, -4};
    rst = s.threeSum(vector);
    s.printVector(rst);
}