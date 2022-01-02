#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int> > graph;
vector<int> used, d, up;
int i, n, m, a, b, tm;
set<int> ArtPoints;
set<int>::iterator iter;

void dfs (int v, int p = -1) // NOLINT(misc-no-recursion)
{
    int i, to, children;
    used[v] = 1;
    d[v] = up[v] = tm++;
    children = 0;
    for (i = 0; i < graph[v].size(); i++)
    {
        to = graph[v][i];
        if (to == p)  continue;
        if (used[to]) {
            up[v] = min(up[v], d[to]);
        }
        else
        {
            dfs (to, v);
            up[v] = min (up[v], up[to]);
            if ((up[to] >= d[v]) && (p != -1)) {
                ArtPoints.insert(v);
            }
            children++;
        }
    }
    if ((p == -1) && (children > 1)) ArtPoints.insert(v);
}

int main()
{
    scanf("%d %d",&n,&m);
    graph.resize(n+1); used.resize(n+1);
    d.resize(n+1); up.resize(n+1);

    for(i = 0; i < m; i++)
    {
        scanf("%d %d",&a,&b);
        graph[a].push_back(b); graph[b].push_back(a);
    }

    tm = 1;
    for(i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    printf("%d\n",ArtPoints.size());
    for(iter = ArtPoints.begin(); iter != ArtPoints.end(); iter++)
        printf("%d\n",*iter);
    return 0;
}
