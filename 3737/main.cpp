#include <iostream>

using namespace std;

int main() {
    int n, temp;

    cin >> n;

    int a[n + 1];

    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        a[i] = temp;
    }


    bool flag = true;
    for (int i = 1; i <= (n/2 + 1); ++i) {
        if (2 * i <= n) {
            if (a[i] > a[2*i]) {
                flag = false;
                break;
            }
        }

        if ((2 * i) + 1  <= n) {
            if (a[i] > a[(2 * i) + 1]) {
                flag = false;
                break;
            }
        }
    }
    
    cout << (flag ? "YES" : "NO") << endl;

    return 0;
}
