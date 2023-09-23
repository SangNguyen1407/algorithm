/*
 * Symbol       Value
 *   I             1
 *   V             5
 *   X             10
 *   L             50
 *   C             100
 *   D             500
 *   M             1000
 * 
 * Example 1:
 *   Input: s = "III"
 *   Output: 3
 *   Explanation: III = 3.
 * Example 2:
 *   Input: s = "LVIII"
 *   Output: 58
 *   Explanation: L = 50, V= 5, III = 3.
 * Example 3:
 *   Input: s = "MCMXCIV"
 *   Output: 1994
 *   Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
       int sum = 0;
       int num = 0;

       for (int i = s.size()-1; i>=0 ; i--)
       {
           switch(s[i]){
               case 'I' : num = 1;   break;
               case 'V' : num = 5;   break;
               case 'X' : num = 10;  break;
               case 'L' : num = 50;  break;
               case 'C' : num = 100; break;
               case 'D' : num = 500; break;
               case 'M' : num = 1000;break;
               default  : num = 0;   break;
           }
           if (4*num < sum)  
               sum -= num;
           else 
               sum += num;
       }
       return sum;        
    }
};

int main (){
    Solution s;
    string intput;

    intput = "III";
    cout << "1. III ->     " << s.romanToInt( intput ) << endl;

    intput = "LVIII";
    cout << "2. LVIII ->   " << s.romanToInt( intput ) << endl;

    intput = "MCMXCIV";
    cout << "3. MCMXCIV -> " << s.romanToInt( intput ) << endl;

}