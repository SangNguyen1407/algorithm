#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    char* colour_1[4]    = { "Blue", "Orange", "Red", "Yellow" };
    char colour_2[4][10] = { "Blue", "Orange", "Red", "Yellow" };
    string colour_3[4]   = { "Blue", "Orange", "Red", "Yellow" };
    std::vector<string> colour_4{ "Blue", "Orange", "Red", "Yellow" };
    int i = 0;
    cout << endl << "colour with *[]" << endl;
    for ( i = 0; i<4; i++){
        cout << colour_1[i] << endl;
    }

    cout << endl << "colour with [][]" << endl;
    for ( i = 0; i<4; i++){
        cout << colour_2[i] << endl;
    }

    cout << endl << "colour with string" << endl;
    for ( i = 0; i<4; i++){
        cout << colour_3[i] << endl;
    }

    cout << endl << "colour with vector" << endl;
    for ( i = 0; i<4; i++){
        cout << colour_4[i] << endl;
    }
}