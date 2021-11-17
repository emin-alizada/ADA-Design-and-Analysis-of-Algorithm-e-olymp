#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

#define MAX 5001
#define INF 0x3F3F3F3F
using namespace std;

int x[MAX], y[MAX];
int used[MAX], dist[MAX];

int dist2(int i, int j) {
    return (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
}

double Prim(int n) {
    memset(dist, 0x3F, sizeof(dist));
    memset(used, 0, sizeof(used));

    double res = 0;
    int cur = 0;
    dist[cur] = 0;
    used[cur] = 1;
    for (int i = 1; i < n; i++) {


//        Relaxation process
        for (int j = 0; j < n; j++) {
            if (!used[j] && (dist2(cur, j) < dist[j])) {
                dist[j] = dist2(cur, j);
            }
        }

//        choosing vertex with minimum distance from current
        int min = INF;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (dist[j] < min)) {
                min = dist[j];
                cur = j;
            }
        }

        used[cur] = 1;
        res += sqrt(dist[cur]);
    }

    return res;
}

//Week 8 - November 12 (prim algorithm)
int main() {
    int n = 1;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        double res = Prim(n);

        printf("%.2lf\n", res);
    }
    return 0;
}