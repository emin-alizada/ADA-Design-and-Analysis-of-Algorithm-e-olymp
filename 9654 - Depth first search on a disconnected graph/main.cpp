#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

int g[MAX][MAX], t = 1, n;

struct Vertex {
    int used, d, f, id;

    Vertex(int i) {
        id = i;
        used = 0;
        d = 0;
        f = 0;
    }
};

int comparator(Vertex a, Vertex b) {
    return a.d < b.d;
}

vector<Vertex> vertex;

void dfsMatrix(int v) {
    if (vertex[v].used == 1) {
        return;
    }

    vertex[v].d = t++;
    vertex[v].used = 1;

    for (int i = 1; i <= n; ++i) {
        if (vertex[i].used == 0 && g[v][i] == 1) {
            dfsMatrix(i);
        }
    }
    vertex[v].f = t++;
}

int main() {
    cin >> n;

    for (int i = 0; i <= n; ++i) {
        vertex.push_back(Vertex(i));
    }

    int a, b;
    while (cin >> a >> b) {
        g[a][b] = 1;
        g[b][a] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        dfsMatrix(i);
    }

    sort(vertex.begin(), vertex.end(), comparator);

    for (int i = 1; i <= n; ++i) {
        printf("Vertex: %d, Gray %d, Black %d\n", vertex[i].id, vertex[i].d, vertex[i].f);
    }

    return 0;
}