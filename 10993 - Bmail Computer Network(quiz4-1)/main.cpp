#include <iostream>
#include <vector>

using namespace std;
const int maximumNumber = 1e6 + 5;

int n, p[maximumNumber];
vector<int> g[maximumNumber], answer;

void dfs(int u, int prev) {
    if (u == n) {
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == prev) {
            continue;
        }
        answer.push_back(v);
        dfs(v, u);
        answer.pop_back();
    }

    return;
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        g[p[i]].push_back(i);
        g[i].push_back(p[i]);
    }

    answer.push_back(1);
    dfs(1, 0);
}
