#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
map<string, int> creatures;
vector<vector<int>> g;
vector<int> used;
int connectedComponentLength, maxx;

void dfsEdgeList(int v) { // NOLINT(misc-no-recursion)
    used[v] = 1;
    connectedComponentLength++;

    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];

        if (used[to] == 0) {
            dfsEdgeList(to);
        }
    }
}

int main() {
    while (scanf("%d %d", &n, &m), n + m){
        g = vector<vector<int>>(n, vector<int>());
        used = vector<int>(n, 0);

        creatures.clear();

        string t1, t2;
        for (int i = 0; i < n; ++i) {
            cin >> t1;
            creatures[t1] = i;
        }

        for (int i = 0; i < m; ++i) {
            cin >> t1 >> t2;
            int to = creatures[t1];
            int from = creatures[t2];

            g[from].push_back(to);
            g[to].push_back(from);
        }

        for (int i = 0; i < n; ++i) {
            if (used[i] == 0) {
                dfsEdgeList(i);
                maxx = max(maxx, connectedComponentLength);
                connectedComponentLength = 0;
            }
        }

        cout << maxx << endl;
        maxx = 0;
    }

    return 0;
}