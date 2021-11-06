#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    int count = 0;
    while (n != 1) {
        if (n%3 == 0) {
            n/=3;
            count++;
        } else {
            n-=1;
            count++;
        }
    }

    cout << count;
    return 0;
}
