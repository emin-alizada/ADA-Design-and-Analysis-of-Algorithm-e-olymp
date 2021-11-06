#include <iostream>

using namespace std;

int main() {
    long long n, a, b, res;
    cin >> n >> a >> b;

    if (n % 2 == 0) {
        res = (a + b) * (n / 2);
    } else {
        res = max(a, b);
        n-=1;
        res += (a + b) * (n / 2);
    }

    cout << res;

    return 0;
}
