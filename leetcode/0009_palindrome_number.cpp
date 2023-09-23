/*
 * Example 1:
 *   Input: x = 121
 *   Output: true
 *   Explanation: 121 reads as 121 from left to right and from right to left.
 * Example 2:
 *   Input: x = -121
 *   Output: false
 *   Explanation: From left to right, it reads -121. From right to left, 
 *                it becomes 121-. Therefore it is not a palindrome.
 * Example 3:
 *   Input: x = 10
 *   Output: false
 *   Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        std::string iPalidrome = std::to_string(x);
        int left = 0;
        int right = iPalidrome.length() - 1;
        if (x < 0){
            return false;
        }

        while(left < right){
        if (iPalidrome[left] != iPalidrome[right]){
                return false;
        }
        left++; 
        right--;
        }
        return true;     
    }
};

int main (){
    Solution s;
    int x = 0;

    x = 121;
    cout << "1. 121     " << s.isPalindrome( x ) << endl;

    x = -121;
    cout << "2. -121    " << s.isPalindrome( x ) << endl;

    x = 10;
    cout << "3. 10      " << s.isPalindrome( x ) << endl;
}