#include <iostream>

#define MAX 26

using namespace std;

int mas[MAX][MAX];
int best;
int n, m, i, a, b;

// TODO analyze the code

void run(int i, int depth) {
//    The variable best maintains the value of the longest path.
    if (depth > best)
        best = depth;
//    Find into which vertex j can we go from i.
    for (int j = 0; j < n; j++)
        if (mas[i][j]) {
//            Delete the edge (i, j) and continue search from the vertex j.
            mas[i][j] = mas[j][i] = 0;
            run(j, depth + 1);
//            Upon return from the function run restore the edge (i, j).
            mas[i][j] = mas[j][i] = 1;
        }
}

int main() {
    while (scanf("%d %d", &n, &m), n + m) {
        memset(mas, 0, sizeof(mas));
        for (i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            mas[a][b] = mas[b][a] = 1;
        }
        best = 0;
        for (i = 0; i < n; i++)
            run(i, 0);
        printf("%d\n", best);
    }
    return 0;
}
