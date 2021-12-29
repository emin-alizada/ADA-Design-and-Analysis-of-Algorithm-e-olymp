#include <iostream>

using namespace std;

int mat[11][11];
int n;

int attacked(int x, int y) {
    if (mat[x][y])return 1;

    for (int i = 1; i <= n; i++) {
        if (y - i >= 1 && mat[x][y - i]) return 1;
        if (y + i <= n && mat[x][y + i]) return 1;
        if (x - i >= 1 && mat[x - i][y]) return 1;
        if (x + i <= n && mat[x + i][y]) return 1;
        if (x - i >= 1 && y - i >= 1 && mat[x - i][y - i]) return 1;
        if (x + i <= n && y + i <= n && mat[x + i][y + i]) return 1;
        if (x + i <= n && y - i >= 1 && mat[x + i][y - i]) return 1;
        if (x - i >= 1 && y + i <= n && mat[x - i][y + i]) return 1;
    }
    return 0;
}

void print(void) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int solve(int x) {
    if (x == 0) {
        print();
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (attacked(i, j) == 1) continue;
            mat[i][j] = 1;
            if (solve(x - 1)) return 1;
            mat[i][j] = 0;
        }
    }
    return 0;
}


int main() {
    scanf("%d", &n);

    if (!solve(n)) {
        puts("Not possible");
    }
    return 0;
}
