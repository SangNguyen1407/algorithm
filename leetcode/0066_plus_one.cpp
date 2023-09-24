/*
    Example 1:

    Input: digits = [1,2,3]
    Output: [1,2,4]
    Explanation: The array represents the integer 123.
    Incrementing by one gives 123 + 1 = 124.
    Thus, the result should be [1,2,4].

    Example 2:

    Input: digits = [4,3,2,1]
    Output: [4,3,2,2]
    Explanation: The array represents the integer 4321.
    Incrementing by one gives 4321 + 1 = 4322.
    Thus, the result should be [4,3,2,2].

    Example 3:

    Input: digits = [9]
    Output: [1,0]
    Explanation: The array represents the integer 9.
    Incrementing by one gives 9 + 1 = 10.
    Thus, the result should be [1,0].

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> rst;
        vector<int> convertRst;

        if(digits.size()==0)
        {
            rst[0] = 1;
            return rst;
        }

        int size = digits.size();
        int carry = 0;
        for (int i = size -1; i>=0; i--)
        {
            if (i == size -1)
            {
                carry = carry + digits[i] + 1; 
            }
            else
            {
                carry = carry + digits[i];
            }

            rst.push_back(carry%10);
            carry = carry/10;
        }
        if (carry == 1)
        {
            rst.push_back(1);
        }

        for (int i = rst.size() -1; i>=0; i--)
        {
            convertRst.push_back( rst[i]);
        //    cout << rst[i];
        }   
        //cout << endl;
        return convertRst;        
    }
};

int main (){
    Solution s;
    vector<int> digits;

    digits = {1, 2, 3};
    s.plusOne( digits );

    digits = {4, 3, 2, 1};
    s.plusOne( digits );

    digits = {9};
    s.plusOne( digits );
}