#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int> > g, gr; // graph and graph reverse
vector<int> used, top, colors;
set<pair<int,int> > s; // set because from one strongly connected component to another might be several edges
int color;

void dfs1(int v)
{
    used[v] = 1;
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) {
            dfs1(to);
        }
    }
    top.push_back(v);
}

void dfs2(int v)
{
    used[v] = 1;
    colors[v] = color;

    for(int i = 0; i < gr[v].size(); i++) {
        int to = gr[v][i];
        if (!used[to]) {
            dfs2(to);
        }
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    g.assign(n+1,vector<int>());
    gr.assign(n+1,vector<int>());
    colors.assign(n+1,-1);


    int a, b;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    used.assign(n+1,0);

    for(int i = 1; i <= n; i++) {
        if (!used[i]) dfs1(i);
    }

    used.assign(n+1,0);

    int  v;
    for(int i = n - 1; i >= 0; i--)
    {
        v = top[i];
        if (!used[v])
        {
            dfs2(v);
            color++;
        }
    }

    for (int i = 1; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            int to = g[i][j];

            if (colors[i] != colors[to]) {
                s.insert(make_pair(colors[i], colors[to]));
            }
        }
    }

    cout << s.size();
    return 0;
}