/*
    Given a sorted array of distinct integers and a target value, 
    return the index if the target is found. 
    If not, return the index where it would be if it were inserted in order.
    You must write an algorithm with O(log n) runtime complexity.
    Example 1:
        Input: nums = [1,3,5,6], target = 5
        Output: 2
    Example 2:
        Input: nums = [1,3,5,6], target = 2
        Output: 1
    Example 3:
        Input: nums = [1,3,5,6], target = 7
        Output: 4
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0)
        {
            return 0;
        }
        int size = nums.size();

        for (int i=0; i < size; i++)
        {
            if((nums[i] == target) || (nums[i] >target))
            {
                return i;
            }
        }
        return size;
        
    }
};


int main (){
    Solution s;
    vector<int> nums;

    nums = {1, 3, 5, 6};
    cout << "1. [1,3,5,6],5 -> " << s.searchInsert(nums, 5) << endl;
    
    nums = {1, 3, 5, 6};
    cout << "1. [1,3,5,6],2 -> " << s.searchInsert(nums, 2) << endl;

    nums = {1, 3, 5, 6};
    cout << "1. [1,3,5,6],7 -> " << s.searchInsert(nums, 7) << endl;
}