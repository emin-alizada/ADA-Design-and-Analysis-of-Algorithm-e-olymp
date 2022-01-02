#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>> > graph;
vector<int> used, d, up;
int i, n, m, a, b, tm;
set<int> Bridges;
set<int>::iterator iter;

void dfs (int v, int p = -1) // NOLINT(misc-no-recursion)
{
    int i, to;
    used[v] = 1;
    d[v] = up[v] = tm++;
    for (i = 0; i < graph[v].size(); i++)
    {
        to = graph[v][i].first;
        if (to == p)  continue;
        if (used[to]) {
            up[v] = min(up[v], d[to]);
        }
        else
        {
            dfs (to, v);
            up[v] = min (up[v], up[to]);
            if (up[to] > d[v]) {
                Bridges.insert(graph[v][i].second);
            }
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    graph.resize(n+1); used.resize(n+1);
    d.resize(n+1); up.resize(n+1);

    for(i = 1; i <= m; i++)
    {
        scanf("%d %d",&a,&b);
        graph[a].push_back(make_pair(b, i));
        graph[b].push_back(make_pair(a, i));
    }

    tm = 1;
    for(i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    printf("%d\n",Bridges.size());
    for(iter = Bridges.begin(); iter != Bridges.end(); iter++) {
        printf("%d ", *iter);
    }
    printf("\n");

    return 0;
}