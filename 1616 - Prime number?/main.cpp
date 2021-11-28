#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned int num;
    bool flag = false;

    cin >> num;

    for (int i = 2; i < sqrt(num); ++i) {
        if (num % i == 0) {
            flag = true;
            break;
        }
    }

    cout << (flag ? "No" : "Yes");

    return 0;
}
