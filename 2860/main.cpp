#include <iostream>

using namespace std;

int main() {
    long num1, num2;

    cin>>num1>>num2;

    long numbersInInterval = num2 - num1 + 1;
    long sumOfNumbersInBetween = ( (num1 + num2) * numbersInInterval ) / 2;

    cout << sumOfNumbersInBetween;

    return 0;
}
