/*
 * Example 1:
 *    Input: s = "25525511135"
 *    Output: ["255.255.11.135","255.255.111.35"]
 * Example 2:
 *    Input: s = "0000"
 *    Output: ["0.0.0.0"]
 * Example 3:
 *    Input: s = "101023"
 *    Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        int size = s.length();
        if ( size < 4 || size > 12 ){
            return ret;
        }
        
        string ipAddr;
        // for example: 0.0.0.0
        int point1 = 0;
        int point2 = 0;
        int point3 = 0;

        for ( int point1 = 1; point1 < size - 2; point1++ ){
            for ( int point2 = point1 + 1; point2 < size - 1; point2++ ){
                for ( int point3 = point2 + 1; point3 < size; point3++ ){
                    ipAddr  = s.substr(0, point1) + ".";
                    ipAddr += s.substr(point1, point2 - point1) + ".";
                    ipAddr += s.substr(point2, point3 - point2) + ".";
                    ipAddr += s.substr(point3, size-1);
                    isIpAddr(ipAddr); 
                    cout << ipAddr << endl;
                }
            }
        }
    }

    int isIpAddr(string ipAddr){
        if (ipAddr.length() < 7){
            return 0;
        }
        cout << "1" << endl;
        int size = ipAddr.length();
        int octec= 0;
        int checkOK = 0;
        for (int i = 0; i < size; i++){
            cout << "2" << endl;
            if ( (char*)ipAddr[i] != "." ){
                octec = octec * 10;
                octec = (int)ipAddr[i];
            }
            else{
                checkOK = ( (octec>=0) &&  (octec<256) )? 1 : 0;
                octec = 0;
            }
            if (!checkOK){
                return 0;
            }
        }
        cout << "3" << endl;
    //    cout << ipAddr << endl;
        return 1;
    }
};

int main (){
    Solution s;
    vector<string> ret;

//    s.restoreIpAddresses( "25525511135" );
//    s.restoreIpAddresses( "255255011035" );
      s.restoreIpAddresses( "123456" );
}