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
#include <cstring>

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
                    if(isIpAddr(
                        s.substr(0, point1).c_str(), 
                        s.substr(point1, point2 - point1).c_str(), 
                        s.substr(point2, point3 - point2).c_str(),
                        s.substr(point3, size-1).c_str())
                    ){
                        ipAddr  = s.substr(0, point1) + ".";
                        ipAddr += s.substr(point1, point2 - point1) + ".";
                        ipAddr += s.substr(point2, point3 - point2) + ".";
                        ipAddr += s.substr(point3, size-1);

                        ret.push_back( ipAddr );
                    }; 
                }
            }
        }

        return ret;
    }

    int isIpAddr(const char *octec1, const char *octec2, const char *octec3, const char *octec4){
        int i1 = atoi(octec1);
        int i2 = atoi(octec2);
        int i3 = atoi(octec3);
        int i4 = atoi(octec4);

        if ( ( (i1>0 && i1<256 && octec1[0] != '0') || (i1==0 && strlen(octec1) == 1) ) &&  
             ( (i2>0 && i2<256 && octec2[0] != '0') || (i2==0 && strlen(octec2) == 1) ) && 
             ( (i3>0 && i3<256 && octec3[0] != '0') || (i3==0 && strlen(octec3) == 1) ) && 
             ( (i4>0 && i4<256 && octec4[0] != '0') || (i4==0 && strlen(octec4) == 1) )
        ){
            return 1;
        }

        return 0;
    }
};

int main (){
    Solution s;
    vector<string> ret;

    s.restoreIpAddresses( "25525511135" );
    s.restoreIpAddresses( "0.0.0.0" );
    s.restoreIpAddresses( "101023" );
}