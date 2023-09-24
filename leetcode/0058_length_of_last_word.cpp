/*
    Example 1:

    Input: s = "Hello World"
    Output: 5
    Explanation: The last word is "World" with length 5.

    Example 2:

    Input: s = "   fly me   to   the moon  "
    Output: 4
    Explanation: The last word is "moon" with length 4.

    Example 3:

    Input: s = "luffy is still joyboy"
    Output: 6
    Explanation: The last word is "joyboy" with length 6.

*/


#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() == 0)
        {
            return 0;
        }

        int size = s.length();
        int count = 0;
        for(int i =size -1; i >= 0; i--)
        {
            if (s.at(i) == ' ')
            {
                if (count == 0)
                {
                    continue;
                }
                break;
            }
            count++;
        }

        return count;        
    }
};


int main (){
    Solution s;
    string inputData;

    inputData = "Hello World";
    cout << "1. \"Hello World\"                   ->   " << s.lengthOfLastWord( inputData ) << endl;

    inputData = "   fly me   to   the moon  ";
    cout << "2. \"   fly me   to   the moon     \"->   " << s.lengthOfLastWord( inputData ) << endl;

    inputData = "luffy is still joyboy";
    cout << "3. \"luffy is still joyboy\"         ->   " << s.lengthOfLastWord( inputData ) << endl;

}