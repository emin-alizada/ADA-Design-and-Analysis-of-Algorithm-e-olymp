#include <iostream>

using namespace std;

// The Euclidean Algorithm
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }

    if (b==0) {
        return a;
    }

    if (a > b) {
        return gcd(a%b, b);
    } else {
        return gcd(a, b%a);
    }
}

int main() {
    int n;

    cin >> n;

    int numbers[n];

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int gcdValue = numbers[0];

    for (int i = 1; i < n; ++i) {
        gcdValue = gcd(gcdValue, numbers[i]);
    }

    cout << gcdValue;

    return 0;
}
