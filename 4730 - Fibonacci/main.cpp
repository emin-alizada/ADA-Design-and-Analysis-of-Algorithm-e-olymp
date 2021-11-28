#include <iostream>

using namespace std;

int fibonacci(unsigned short number) {

    if (number == 0 || number == 1) {
        return 1;
    }

    return fibonacci(number - 1) + fibonacci(number - 2);
}



int main() {
    unsigned short required_fibonacci_number;

    cin >> required_fibonacci_number;

    cout << fibonacci(required_fibonacci_number);

    return 0;
}
