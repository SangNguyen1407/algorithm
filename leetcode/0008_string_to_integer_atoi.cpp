/*
 * Example 1:
 *   Input: s = "42"
 *   Output: 42
 * 
 * Example 2:
 *    Input: s = "   -42"
 *    Output: -42
 * 
 * Example 3:
 *   Input: s = "4193 with words"
 *   Output: 4193
 * 
 * numbers is in the range [-2^31, 2^31 - 1]
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long int_min = -2147483648;
        long long int_max = 2147483647;
        char sData[s.length()+1];
        int i = 0;
        memset (sData, '0', s.length()+1);
        strcpy(sData, s.c_str());
        long long retval = 0;
        int sign = 0;
        int isNum = 0;

        for (i=0; i<s.length()+1; i++){
            if ((sData[i]>= '0' && sData[i]<= '9') 
                && (retval > int_min && retval < int_max)){
                retval = retval*10 + sData[i]-'0'; 
                isNum = 1;
            }
            else if (sData[i] == '-' || sData[i] == '+' || sData[i] == ' '){
                if ((sData[i] == '-' || sData[i] == '+') && (sign == 0 && isNum == 0)){
                    sign = (sData[i] == '-')? -1 : 1;
                }
                else if (((sData[i] == '-' || sData[i] == '+')||(sData[i] == ' ')) 
                        && (isNum == 1 || sign != 0 || retval != 0)){
                    break;
                }
            }
            else if (sData[i] != ' '){
                break;
            }
        }

        if (sign != 0){
            retval = retval * sign;
        }

        if (retval < int_min){
            retval = int_min;
        }
        
        if (retval > int_max){
            retval = int_max;
        }

        return retval;
    }
};


int main (){
    Solution s;
    cout << "1. " << s.myAtoi("42") << endl;
    cout << "2. " << s.myAtoi("   -42") << endl;
    cout << "3. " << s.myAtoi("4193 with words") << endl;
}