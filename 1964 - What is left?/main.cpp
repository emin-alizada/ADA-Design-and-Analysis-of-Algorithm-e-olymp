#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n+1, -1);
    bool flag = false;

    for (int i = 1; i <= n; ++i) {
        a[i] = i;
    }

    int count;
    while (!flag) {
        count = 0;

        for (int i = 1; i <= n; ++i) {
            if (a[i] != -1) {
                count++;
                if (count % 2 == 0) {
                    a[i] = -1;
                }
            }
        }

        count = (count + 1) / 2;
        if (count == 1) {
            flag = true;
            break;
        }

        count = 0;

        for (int i = 1; i <= n; ++i) {
            if (a[i] != -1) {
                count++;
                if (count % 2 == 1) {
                    a[i] = -1;
                }
            }
        }

        count = (count - 1) / 2;
        if (count == 1) {
            flag = true;
            break;
        }

        count = 0;

        for (int i = 1; i <= n; ++i) {
            if (a[i] != -1) {
                count++;
                if (count % 3 == 0) {
                    a[i] = -1;
                }
            }
        }

        count = count - (count / 3);
        if (count == 1) {
            flag = true;
            break;
        }

    }

    for (int i = 1; i <= n; ++i) {
        if (a[i] != -1) {
            cout << a[i];
            break;
        }
    }

    return 0;
}
