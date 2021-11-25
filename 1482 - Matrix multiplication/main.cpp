#include <iostream>

using namespace std;

// Matrix multiplication
int main() {
    int na,ma, nb,mb;

    cin >> na >> ma;

    int a[na][ma];

    for (int i = 0; i < na; ++i) {
        for (int j = 0; j < ma; ++j) {
            cin >> a[i][j];
        }
    }

    cin >> nb >> mb;

    int b[nb][mb];

    for (int i = 0; i < nb; ++i) {
        for (int j = 0; j < mb; ++j) {
            cin >> b[i][j];
        }
    }

    if (ma != nb) {
        cout << -1;
    } else {
        int c[na][mb];

        memset(c, 0, sizeof(c));

        for (int i = 0; i < na; ++i) {
            for (int j = 0; j < nb; ++j) {
                for (int k = 0; k < mb; ++k) {
                    c[i][k] += a[i][j] * b[j][k];
                }
            }
        }

        cout << na << " " << mb << endl;

        for (int i = 0; i < na; ++i) {
            for (int j = 0; j < mb; ++j) {
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
