#include <iostream>

using namespace std;

template <typename T>
bool is_happy(T num){
    T sum = 0;
    T temp = 0;
    while (num > 9){
        while (num > 9){
            temp = num % 10;
            sum += temp;
            num /= 10;
        }
        num = sum;
        sum = 0;
    }
    return (num == 1)? true: false;
}

int main (){
    int n;
    std::cout << "Enter a number: ";
    std::cin  >> n;

    if (is_happy(n)){
        std::cout << n << " is a happy number" << endl;
    }
    else{
        std::cout << n << " is NOT a happy number" << endl;
    }

    return 0;
}