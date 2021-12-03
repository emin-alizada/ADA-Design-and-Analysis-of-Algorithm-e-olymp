#include <iostream>
#define MAX 101

using namespace std;

int n, g[MAX][MAX], used[MAX], countEdges = 0, countVisited = 0;

void dfsMatrix(int v) {
    used[v] = 1;
    countVisited++;

    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0 && g[v][i] == 1) {
            dfsMatrix(i);
        }
    }
}

// Week 11: November 29 - December 5 - DFS (Depth First Search)
int main() {
    cin>>n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 1) {
                countEdges++;
            }
        }
    }

    dfsMatrix(1);

//    It's a tree if number of edges is n-1 and we can visit all edges
    if (countEdges / 2 == n - 1 && countVisited == n) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
