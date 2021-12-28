#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<long long> > g, gr; // graph and graph reverse
vector<long long> used, top, colors;
long long color = 0;

void dfs1(long long v) {
    used[v] = 1;
    for (long long i = 0; i < g[v].size(); i++) {
        long long to = g[v][i];
        if (!used[to]) {
            dfs1(to);
        }
    }
    top.push_back(v);
}

void dfs2(long long v) {
    used[v] = 1;
    colors[v] = color;

    for (long long i = 0; i < gr[v].size(); i++) {
        long long to = gr[v][i];
        if (!used[to]) {
            dfs2(to);
        }
    }
}

int main() {
    long long n, m;
    cin >> n >> m;
    g.assign(n, vector<long long>());
    gr.assign(n, vector<long long>());
    colors.assign(n, -1);


    long long a, b;
    for (long long i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    used.assign(n, 0);

    for (long long i = 0; i < n; i++) {
        if (!used[i]) {
            dfs1(i);
        }
    }

    used.assign(n, 0);

    long long v, numberOfStronglyConnectedCmponents = 0;
    for (long long i = n - 1; i >= 0; i--) {
        v = top[i];
        if (!used[v]) {
            dfs2(v);
            numberOfStronglyConnectedCmponents++;
            color++;
        }
    }

    used = vector<long long>(numberOfStronglyConnectedCmponents, 1);

//    from each strongly connected components there should be at least one outgoing and one incoming
    set<long long> out;
    set<long long> in;

    for (long long i = 0; i < g.size(); i++) {
        for (long long j = 0; j < g[i].size(); j++) {
            long long to = g[i][j];
            // check edge i -> to if they in the same scc.
            if (colors[i] != colors[to]) {
                used[colors[to]] = 0;
                out.insert(colors[i]);
                in.insert(colors[to]);
            }
        }
    }

    long long c = 0;

    for (long long i = 0; i < used.size(); i++) {
        if (used[i]) {
            c++;
        }
    }

    if(numberOfStronglyConnectedCmponents == 1) {
        cout << c << " " << 0;
    } else {
        cout << c << " " << max( (numberOfStronglyConnectedCmponents - out.size()), (numberOfStronglyConnectedCmponents - in.size()) );
    }
    return 0;
}