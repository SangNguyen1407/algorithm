#include <iostream>
#include <string>

using namespace std;

string previousGeneration(string number){
    int size_of_number = number.size();
    int bit_position = 0;

    // add bit 1 into number
    for(bit_position = size_of_number-1; bit_position>=0; bit_position--){
        if (number.at(bit_position) == '1'){
            number.at(bit_position) = '0';
            break;
        }
        else{
            number.at(bit_position) = '1';
        }
    }

    // add the first position of bit
    if (number[bit_position] < 0){
        number = number.substr(1, size_of_number - 1);
    }

    return number;
}

int main (){
    string number = "100100";
    cout << "next number of " << number << " is " << previousGeneration(number) << endl;

    number = "0000";
    cout << "next number of " << number << " is " << previousGeneration(number) << endl;
}