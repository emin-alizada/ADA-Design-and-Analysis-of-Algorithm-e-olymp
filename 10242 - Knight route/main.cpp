#include <iostream>

#define MAX 9

using namespace std;

int sol[MAX][MAX];
int n;

int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int isSafe(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1);
}

void printSolution() {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++)
            printf("%2d ", sol[x][y]);
        printf("\n");
    }
}

int solveKTUtil(int x, int y, int movei) {
    sol[x][y] = movei;
    if (movei == n * n) return 1;
    for (int k = 0; k < 8; k++) {
        int next_x = x + xMove[k];
        int next_y = y + yMove[k];
        if (isSafe(next_x, next_y)) {
            if (solveKTUtil(next_x, next_y, movei + 1) == 1) return 1;
        }
    }
    sol[x][y] = -1;
    return 0;
}

int solve() {
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            sol[x][y] = -1;

    if (solveKTUtil(0, 0, 1) == 0) {
        printf("Solution does not exist");
        return 0;
    } else {
        printSolution();
    }
    return 1;
}


int main() {
    scanf("%d", &n);
    solve();

    return 0;
}
