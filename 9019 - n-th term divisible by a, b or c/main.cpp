#include <iostream>

using namespace std;


int a, b, c, x;

// Recursive function to return gcd of a and b
long long gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int f(int n) {
//    for better understanding
//    cout << "Divisible by " << a << " are " << (n / a) << endl;
//    cout << "Divisible by " << b << " are " << (n / b) << endl;
//    cout << "Divisible by " << c << " are " << (n / c) << endl;
//
//    cout << "Divisible by  both " << a << " and " << b << " are " << (n / lcm(a, b)) << endl;
//    cout << "Divisible by  both " << b << " and " << c << " are " << (n / lcm(b, c)) << endl;
//    cout << "Divisible by  both " << a << " and " << c << " are " << (n / lcm(a, c)) << endl;
//
//    cout << "Divisible by  both " << a << " and " << b << " and " << c << " are " << (n / lcm(lcm(a, b), c) ) << endl;

    return (n / a) + (n / b) + (n/c) - ( (n / lcm(a, b)) + (n / lcm(b, c)) + (n / lcm(a, c)) - (n / lcm(lcm(a, b), c) ) );
}

int binarySearch(int left, int right) {
    while (left < right) {
        int mid = (left + right) / 2;
        if (f(mid) < x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}


int main() {
    cin >> a >> b >> c >> x;

    int res = binarySearch(1, 1000000000);
//    for test
//    int res = f(15);

    cout << res;

    return 0;
}