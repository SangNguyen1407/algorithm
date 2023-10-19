#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string str_test = "TestForAll";
    char* char_test = "TestForAll";

    // 1. replace a character in string and char*
    str_test[1] = 'E';
    cout << "str_test: " << str_test << endl; 
    for (int i=0; i < str_test.size(); i++){
        cout << str_test[i] << " ";
    }
    cout << endl;

    cout << "char_test: " << char_test << endl; 
    // str_test[1] = 'E'; <- can not replace a character in char*
    // cout << "char_test: " << char_test << endl; 
    int size = strlen(char_test);
    char *newChar = new char[size + 1];
    int position = 0;
    while( position < size+1){
        if (position == 1){
            newChar[position] = 'E';
            position++;
            continue;
        }
        newChar[position] = *char_test;
        char_test++;
        position++;
    }
    newChar[position] = '\0';
    cout << newChar << endl;
}