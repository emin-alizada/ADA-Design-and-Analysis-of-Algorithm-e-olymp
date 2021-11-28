#include <iostream>

using namespace std;

int repr(int dsu[], int i) {
    int r = dsu[i];
    while (r != dsu[r]){
        r = dsu[r];
    }
    return r;
}

void make_union(int dsu[], int a, int b) {
    a = repr(dsu, a);
    b = repr(dsu, b);

    if (a == b) {
        return;
    } else {
        dsu[a] = b;
    }
}

int numberOfSets(int dsu[], int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == dsu[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, m;
    int e1, e2;
    cin >> n >> m;

    int dsu[n + 1];

    for (int i = 1; i <= n; ++i) {
        dsu[i] = i;
    }

    for (int i = 1; i <= m; ++i) {
        cin >> e1 >> e2;
        make_union(dsu, e1, e2);
    }

//    Graph is connected if it contains only one connected component.
    cout << (numberOfSets(dsu, n) == 1 ? "YES" : "NO" );
    return 0;
}
