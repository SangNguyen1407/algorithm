/* Example 1:

    Input: tokens = ["2","1","+","3","*"]
    Output: 9
    Explanation: ((2 + 1) * 3) = 9

    Example 2:

    Input: tokens = ["4","13","5","/","+"]
    Output: 6
    Explanation: (4 + (13 / 5)) = 6

    Example 3:

    Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    Output: 22
    Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    = ((10 * (6 / (12 * -11))) + 17) + 5
    = ((10 * (6 / -132)) + 17) + 5
    = ((10 * 0) + 17) + 5
    = (0 + 17) + 5
    = 17 + 5
    = 22

*/



#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0){
            return 0;
        }
        vector<long long int> temp;
        string cToken; 
        int i = 0;
        int result = 0;
        for( int i = 0; i < tokens.size(); i++ ){ 
            if (tokens[i] != "+" && tokens[i] != "-" 
                && tokens[i] != "*" && tokens[i] != "/"){
                    temp.push_back(stoi(tokens[i]));
            }
            else{
                long long int temp1 = temp.back();
                temp.pop_back();
                long long int temp2 = temp.back();
                temp.pop_back();
                if (tokens[i] == "+"){
                    temp.push_back(temp2 + temp1);
                }else if (tokens[i] == "-"){
                    temp.push_back(temp2 - temp1);
                }else if (tokens[i] == "/"){
                    temp.push_back(temp2 / temp1);
                }else if (tokens[i] == "*"){
                    temp.push_back(temp2 * temp1);
                }
            }
        }
        return temp.back();        
    }
};


int main (){
    Solution s;
    vector<string> tokens;

    tokens = {"2","1","+","3","*"};
    cout << "1. ((2 + 1) * 3) = " << s.evalRPN( tokens ) << endl;

    tokens = {"4","13","5","/","+"};
    cout << "2. (4 + (13 / 5)) = " << s.evalRPN( tokens ) << endl;

    tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << "3. ((10 * (6 / ((9 + 3) * -11))) + 17) + 5 = " << s.evalRPN( tokens ) << endl;
}