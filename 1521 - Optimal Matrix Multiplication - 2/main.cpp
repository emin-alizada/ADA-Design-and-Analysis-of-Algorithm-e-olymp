#include <iostream>
#include <cstring>

#define INF 0x3F3F3F3F3F3F3F3FLL

using namespace std;

#define MAX 11

long long m[MAX][MAX], s[MAX][MAX], p[MAX];

long long Mult(int i, int j) {
    if (m[i][j] == INF) {
        for (int k = i; k <= j - 1; k++) {
            long long temp = Mult(i, k) + Mult(k + 1, j) + p[i - 1] * p[k] * p[j];
            if (temp < m[i][j]) {
                m[i][j] = temp;
                s[i][j] = k;
            }
        }
    }
    return m[i][j];
}

string Print(int i, int j)
{
    if (i == j) return "A" + to_string(i);
    return "(" + Print(i,s[i][j]) + " x " + Print(s[i][j]+1,j) + ")";
}

// Week 10: November 24 - Matrix multiplication
int main() {
    int n, counter = 1;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        memset(m, 0x3F, sizeof(m));
        for (int i = 1; i <= n; i++) {
            cin >> p[i-1] >> p[i];
            m[i][i] = 0;
        }

        Mult(1, n);

        cout <<  "Case " << counter << ": ";
        if (n==1) {
            cout << "(A1)";
        } else {
            cout << Print(1,n);
        }

        cout << endl;

        counter++;
    }
    return 0;
}