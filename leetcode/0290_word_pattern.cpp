/*
    Example 1:

    Input: pattern = "abba", s = "dog cat cat dog"
    Output: true

    Example 2:

    Input: pattern = "abba", s = "dog cat cat fish"
    Output: false

    Example 3:

    Input: pattern = "aaaa", s = "dog cat cat dog"
    Output: false

*/
#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        if(pattern.empty() || s.empty())
        {
            return false;
        }

        std::map<char, string> wordCache;
        std::map<string, bool> checked;
        std::vector<string> wordList;
        int size = pattern.length();

        char* tok = strtok((char*)s.c_str(), " ");
        while(tok) {
            wordList.push_back(tok);
            tok = strtok(NULL, " ");
        }

        if (wordList.size() != pattern.length())
        {
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            if (wordCache.find(pattern[i]) == wordCache.end())
            {
                if (checked.find(wordList[i]) != checked.end())
                {
                    return false;
                }
                checked[wordList[i]] = true;
                wordCache[pattern[i]] = wordList[i];
            }
            else if(wordCache[pattern[i]].compare(wordList[i]) != 0)
            {
                return false;
            }
        }

        return true;

    }
};


int main (){
    Solution s;
    string pattern;
    string word;

    pattern = "abba";
    word    = "dog cat cat dog";
    cout << "1. " << s.wordPattern(pattern, word) << endl;

    pattern = "abba";
    word    = "dog cat cat fish";
    cout << "2. " << s.wordPattern(pattern, word) << endl;

    pattern = "aaaa";
    word    = "dog cat cat dog";
    cout << "3. " << s.wordPattern(pattern, word) << endl;
}