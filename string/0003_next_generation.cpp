#include <iostream>
#include <string>

using namespace std;

string nextGeneration(string number){
    int size_of_number = number.size();
    int bit_position = 0;

    // add bit 1 into number
    for(bit_position = size_of_number-1; bit_position>=0; bit_position--){
        if (number.at(bit_position) == '0'){
            number.at(bit_position) = '1';
            break;
        }
        else{
            number.at(bit_position) = '0';
        }
    }

    // add the first position of bit
    if (bit_position < 0){
        number = "1" + number;
    }

    return number;
}

int main (){
    string number = "100101";
    cout << "next number of " << number << " is " << nextGeneration(number) << endl;

    number = "11111";
    cout << "next number of " << number << " is " << nextGeneration(number) << endl;
}