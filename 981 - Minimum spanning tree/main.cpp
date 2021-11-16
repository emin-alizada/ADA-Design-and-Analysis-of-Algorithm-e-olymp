#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXV 20001
#define MAXE 100001
using namespace std;

struct Edge
{
    int u, v,dist;
} e[MAXE];

int repr[MAXV], sizeOfSet[MAXV], res;

void swap(int &x, int &y)
{
    int t = x; x = y; y = t;
}

int Repr(int n)
{
    if (n == repr[n]) return n;
    return repr[n] = Repr(repr[n]);
}

int Union(int x,int y)
{
    x = Repr(x); y = Repr(y);
    if(x == y) return 0;

    if (sizeOfSet[x] < sizeOfSet[y]) swap(x, y);
    repr[y] = x;
    sizeOfSet[x] += sizeOfSet[y];
    return 1;
}

int comp(Edge a, Edge b)
{
    return (a.dist < b.dist);
}
// Week 8 - 12 nov (MST) (Union set)
int main()
{
    int i, n, m;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++)
    {
        repr[i] = i;
        sizeOfSet[i] = 1;
    }

    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].dist);
    }

    sort(e, e + m, comp);

    res = 0;
    for(i = 0; i < m; i++) {
//        add to res if not in the same set
        if (Union(e[i].u, e[i].v)) {
            res += e[i].dist;
        }
    }

    cout << res << endl;

    return 0;
}
