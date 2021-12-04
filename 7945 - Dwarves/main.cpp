#include <iostream>
#include <vector>
#include <map>
using namespace std;

int maxDwarves = 10001;
int n, counter = 1;
string s1, s2, op;
vector<vector<int> > g;
vector<int> used;
map<string , int> m;
bool cycleFlag = false;

void dfsEdgeList(int v) {
    if (cycleFlag) {
        return;
    }

    used[v] = 1;

    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];

        if (used[to] == 0) {
            dfsEdgeList(to);
        }

        if (used[to] == 1) {
            cycleFlag = true;
        }
    }

    used[v] = 2;
}

int main() {
    cin >> n;
    g.resize(maxDwarves);
    used.resize(maxDwarves);

    for (int i = 0; i < n; ++i) {
        cin >> s1 >> op >> s2;

        if (m[s1] == 0) {
            m[s1] = counter;
            counter++;
        }

        if (m[s2] == 0) {
            m[s2] = counter;
            counter++;
        }

        int from = m[s1];
        int to = m[s2];

        if (op == ">") {
            g[from].push_back(to);
        } else {
            g[to].push_back(from);
        }
    }

    for (int i = 1; i < maxDwarves; ++i) {
        if (used[i] == 0) {
            dfsEdgeList(i);
        }
    }

    cout << (cycleFlag ? "impossible" : "possible") << endl;

    return 0;
}
