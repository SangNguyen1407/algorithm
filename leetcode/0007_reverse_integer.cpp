/**
 * Example 1:
 *      Input: x = 123
 *      Output: 321
 * Example 2:
 *      Input: x = -123
 *      Output: -321
 * Example 3:
 *      Input: x = 120
 *      Output: 21
 */


#include<iostream>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long reverseNumber = 0;
        long remainder = 0;

        while(x != 0)
        {
            remainder = x%10;
            x = x/10;
            if (reverseNumber > INT_MAX/10 || (reverseNumber == INT_MAX / 10 && remainder > 7)) 
               return 0;        
            if (reverseNumber < INT_MIN/10 || (reverseNumber == INT_MIN / 10 && remainder < -8)) 
               return 0;
            reverseNumber = reverseNumber*10 + remainder;
            }

        return reverseNumber;        
    }
};

int main (){
    Solution s;
    int ret = 0;
    
    ret = s.reverse(123);
    cout << "1. " << ret  << endl;

    ret = s.reverse(-123);
    cout << "2. " << ret  << endl;

    ret = s.reverse(120);
    cout << "3. " << ret  << endl;

    return 1;
}