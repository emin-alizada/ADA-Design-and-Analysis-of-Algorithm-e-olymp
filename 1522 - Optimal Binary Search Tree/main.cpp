#include <iostream>
#define MAX 252

using namespace std;


int e[MAX], t[MAX][MAX], sum[MAX];

int weight(int i, int j)
{
    if (i > j) return 0;
    return sum[j] - sum[i-1];
}

int f(int i, int j) {
    if (i >= j) {
        return 0;
    }

    if (t[i][j] == INT32_MAX) {
        for (int k = i; k <= j; ++k) {
            int tempSum = weight(i, k-1) + f(i, k - 1) + weight(k+1, j) + f(k + 1, j);

            if (t[i][j] > tempSum) {
                t[i][j] = tempSum;
            }
        }
    }

    return t[i][j];
}

// Week 10: November 24 - Optimal Binary Search Tree
int main() {
    int n;
    while (cin >> n) {

        for (int i = 0; i < MAX; ++i) {
            for (int j = 0; j < MAX; ++j) {
                t[i][j] = INT32_MAX;
            }
        }

        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> e[i];
            sum[i] = sum[i-1] + e[i];
        }

        cout << f(1, n) << endl;
    }
    return 0;
}

//6 1 3 5 10 20 30