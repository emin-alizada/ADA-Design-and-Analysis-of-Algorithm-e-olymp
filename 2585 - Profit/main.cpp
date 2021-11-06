#include <iostream>

using namespace std;

int main() {
    int n;

    cin >>n;

    long long m = 0;
    long long temp, sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        sum += temp;
        if (sum > m) {
            m = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }

    cout << m;
    return 0;
}
