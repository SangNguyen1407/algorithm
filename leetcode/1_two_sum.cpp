/* Give arr of integer nums and an integer target
 * return sum two numbers such that they app up to target
 * for example: 
 *  Input: nums = [2,7,11,15], target = 9
 *  Output: [0,1]
 *  Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 */

#include<iostream>
#include<string>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vRst;
        int sum = 0;
        int size = nums.size();
        if (size == 1 && nums[0] == target)
        {
            vRst.push_back(0);
            return vRst;
        }

        for(int i=0; i< size - 1; i++)
        {
            for(int j=i+1; j < size; j++)
            {
                if (nums[j] + nums[i] == target)
                {
                    vRst.push_back(i);
                    vRst.push_back(j);
                    return vRst;
                }
            }
        }

        return vRst;         
        }
};


int main (){
    std::vector<int> nums = {1, 2, 3, 4, 3, 2, 1};
    std::vector<int> result; 
    Solution sol;

    result = sol.twoSum(nums, 6);
    
    for (int x : result){
        cout << x << " ";
    }
}