#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 1000000000
using namespace std;

struct Edge
{
    int u, v, dist;
    Edge(int u, int v, int dist) : u(u), v(v), dist(dist) {};
};

vector<Edge> e;
vector<int> rep, danger;
int res, i, n, m, p;
int u, v, dist, cnt;

int Repr(int n)
{
    while (n != rep[n]) n = rep[n];
    return n;
}

int Union(int x, int y)
{
    x = Repr(x); y = Repr(y);
    if (x == y) return 0;
    rep[y] = x;
    return 1;
}

int comp(Edge a, Edge b)
{
    return (a.dist < b.dist);
}

int main(void)
{
    scanf("%d %d %d", &n, &m, &p);
    rep.resize(n + 1);
    for (i = 1; i <= n; i++) {
        rep[i] = i;
    }

    danger.resize(n + 1);

    for (i = 0; i < p; i++)
    {
        scanf("%d", &u);
        danger[u] = INF;
    }

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &dist);
        if ((danger[u] > 0) && (danger[v] == 0))
            danger[u] = min(danger[u], dist);
        if ((danger[v] > 0) && (danger[u] == 0))
            danger[v] = min(danger[v], dist);
        if ((danger[u] == 0) && (danger[v] == 0))
            e.push_back(Edge(u, v, dist));
    }

    if (m == 0)
    {
        puts("0");
        return 0;
    }

    if (m == 1)
    {
        printf("%d\n", dist);
        return 0;
    }

    sort(e.begin(), e.end(), comp);

    cnt = res = 0;
    for (i = 0; i < e.size(); i++) {
        if (Union(e[i].u, e[i].v)) {
            res += e[i].dist;
            cnt++;
        }
    }

    for (i = 1; i <= n; i++) {
        if (danger[i] > 0) {
            res += danger[i];
            cnt++;
        }
    }

    if ((cnt != n - 1) || (res > INF)) {
        puts("impossible");
    }
    else {
        printf("%d\n", res);
    }

    return 0;
}
