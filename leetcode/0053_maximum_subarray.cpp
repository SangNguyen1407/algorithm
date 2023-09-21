/*
 * Example 1:
 *    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 *    Output: 6
 *    Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 * Example 2:
 *    Input: nums = [1]
 *    Output: 1
 *    Explanation: The subarray [1] has the largest sum 1.
 * Example 3:
 *    Input: nums = [5,4,-1,7,8]
 *    Output: 23
 *    Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    if(nums.size()==0)
    {
        return 0;
    } else if(nums.size() == 1)
    {
        return (nums[0]);
    }
    int max_sum = 0;
    int find_max_sum = 0;
    int size = nums.size();
    int flag_neg_num = 1; // all numbers is negative
    for (int i=0; i< size; i++)
    {
        if (flag_neg_num == 1)
        {
            if (nums[i] >= 0)
            {
                flag_neg_num = 0;
                find_max_sum = 0;
            }
            else
            {
                if (find_max_sum == 0 || find_max_sum < nums[i])
                {
                    find_max_sum = nums[i];
                }
                continue;
            }
        }
        find_max_sum += nums[i];
        if (max_sum < find_max_sum)
        {
            max_sum = find_max_sum;
        }

        if (find_max_sum < 0)
        {
            find_max_sum = 0;
        } 
    }
    if (flag_neg_num == 1 && max_sum == 0)
    {
        max_sum = find_max_sum;
    }
    return max_sum;       
    }
};

int main (){
    Solution s;
    int ret = 0;
    vector<int> vec;

    vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "1. " << s.maxSubArray(vec) << endl;

    vec = {1};
    cout << "2. " << s.maxSubArray(vec) << endl;

    vec = {5, 4, -1, 7, 8};
    cout << "2. " << s.maxSubArray(vec) << endl;
}