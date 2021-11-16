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

int repr[MAXV], sizeOfSet[MAXV];

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
    int t;

    cin >> t;

    while (t--) {
        int i, n, m, p, q;
        scanf("%d %d %d %d", &n, &m, &p, &q);

        for(i = 1; i <= n; i++)
        {
            repr[i] = i;
            sizeOfSet[i] = 1;
        }

        for(i = 0; i < m; i++) {
            scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].dist);
        }

        sort(e, e + m, comp);

        bool flag = false;
        for(i = 0; i < m; i++) {
//        add to res if not in the same set
            if (Union(e[i].u, e[i].v)) {
                if ((p == e[i].u && q == e[i].v) || (p == e[i].v && q == e[i].u) ) {
                    flag = true;
                    break;
                }
            }
        }

        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}
