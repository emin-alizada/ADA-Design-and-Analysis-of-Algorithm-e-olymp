#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define MAX 101

int graph[MAX][MAX];
vector<int> used, d, up;
int i, n, m, a, b, tm, start;
set<int> ArtPoints;
set<int>::iterator iter;

void dfs (int v, int p = -1) // NOLINT(misc-no-recursion)
{
    int i, to, children;
    used[v] = 1;
    d[v] = up[v] = tm++;
    children = 0;
    for (i = 1; i <= n; i++)
    {
        if (graph[v][i] == 1) {
            to = i;
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
    }
    if ((p == -1) && (children > 1)) ArtPoints.insert(v);
}

int main()
{
    scanf("%d %d",&n,&m);
    used.resize(n+1);
    d.resize(n+1); up.resize(n+1);

    for(i = 0; i < m; i++)
    {
        scanf("%d %d",&a,&b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    scanf("%d", &start);

    tm = 1;
    dfs(start);

    for (int j = 1; j <= n; ++j) {
        printf("%d %d\n", d[j], up[j]);
    }
    return 0;
}
