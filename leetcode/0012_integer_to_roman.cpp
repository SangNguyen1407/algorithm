/*
    Example 1:

    Input: num = 3
    Output: "III"
    Explanation: 3 is represented as 3 ones.

    Example 2:

    Input: num = 58
    Output: "LVIII"
    Explanation: L = 50, V = 5, III = 3.

    Example 3:

    Input: num = 1994
    Output: "MCMXCIV"
    Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

*/

#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        if(num < 1 || num > 3999)
        {
            return "";
        }
        string strRoman = "";
        int iNum[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string roman[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int i=12;   

        while(num >0)
        {
            int div = num/iNum[i];
            num = num%iNum[i];
            while(div--)
            {
                strRoman += roman[i];
            }
            i--;
        }

        return strRoman;        
    }
};


int main (){
    Solution s;
    int num;

    num = 3;
    cout << "1. 3    ->   " << s.intToRoman( num ) << endl;

    num = 58;
    cout << "2. 58   ->   " << s.intToRoman( num ) << endl;

    num = 1994;
    cout << "3. 1994 ->   " << s.intToRoman( num ) << endl;

}