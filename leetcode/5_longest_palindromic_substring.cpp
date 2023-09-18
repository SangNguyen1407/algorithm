/**
 * Example 1:
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * 
 * Example 2:
 * Input: s = "cbbd"
 * Output: "bb"
 */

#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0)
        {
            return "";
        }
        int left = 0;
        int right  = 0;
        int len = s.size();

        for (int center = 0; center < len; center++)
        {
            int len1 = PalindromeLen(center, center,s); 
            int len2 = PalindromeLen(center, center+1,s);

            // "bab"
            if (len1 > right - left)
            {
                left = center - len1/2;
                right = left + (len1-1);
            }

            // "baab"
            if (len2 > right - left)
            {
                left = center - (len2/2 -1);
                right = left + (len2-1);
            }
        }
        return (s.substr(left, right-left+1));   
    }

    int PalindromeLen(int left, int right, string s)
    {
        int len = 0;
        while (left > -1 && right < s.size())
        {
            if (s[left] == s[right])
            {
                len = right - left +1;
                right++;
                left--;
            }
            else
            {
                break;
            }
        }
        return len;
    }
};

int main (){
    Solution s;
    string ret = s.longestPalindrome("babad");
    ret = (ret.length() > 1)?  ret : "no Palindrome ";
    cout << "1. " << ret  << endl;

    ret = s.longestPalindrome("Aibohphobia");
    ret = (ret.length() > 1)?  ret : "no Palindrome ";
    cout << "2. " << ret  << endl;

    ret = s.longestPalindrome("Taco cat");
    ret = (ret.length() > 1)?  ret : "NO PALINDROME ";
    cout << "3. " << ret  << endl;

    ret = s.longestPalindrome("Racecar");
    ret = (ret.length() > 1)?  ret : "no Palindrome ";
    cout << "4. " << ret  << endl;
}