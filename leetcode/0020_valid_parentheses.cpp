/*
 * Example 1:
 *   Input: s = "()"
 *   Output: true
 * Example 2:
 *   Input: s = "()[]{}"
 *   Output: true
 * Example 3:
 *   Input: s = "(]"
 *   Output: false
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s == "")
        {
           return true;
        }

        std::stack<char> stack;
        for (int i = 0; i<s.size() ; i++)
        {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(' )
            {
                stack.push(s[i]);
            }
            else if (s[i] == ']' || s[i] == '}' || s[i] == ')' )
            {
                if (stack.size() == 0)
                   return false;
                switch (s[i])
                {
                case  ']':
                    if (stack.top() != '[') return false;
                    break;
                case  '}':
                    if (stack.top() != '{') return false;
                    break;
                case  ')':
                    if (stack.top() != '(') return false;
                    break;

                default:
                    break;
                }

                stack.pop();
            }
        }
       if (stack.size() == 0)
           return true;

        return false;        
    }
};


int main (){
    Solution s;
    string inputData;

    inputData = "()";
    cout << "1. ()     " << s.isValid( inputData ) << endl; 

    inputData = "()[]{}";
    cout << "2. ()[]{} " << s.isValid( inputData ) << endl;

    inputData = "(]";
    cout << "3. (]     " << s.isValid( inputData ) << endl;
}