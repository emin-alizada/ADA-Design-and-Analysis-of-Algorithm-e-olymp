#include <iostream>

using namespace std;

int repr(int dsu[], int i) {
//    Path compression heuristic
    if (i == dsu[i]) {
        return i;
    }
    return dsu[i] = repr(dsu, dsu[i]);
}

void make_union(int dsu[], int depthDsu[], int a, int b) {
    a = repr(dsu, a);
    b = repr(dsu, b);

    if (a == b) {
        return;
    } else {
        if (depthDsu[a] > depthDsu[b]) {
            swap(a, b);
        }
        dsu[a] = b;
        if (depthDsu[a] == depthDsu[b]) {
            depthDsu[b]++;
        }
    }
}

void setCreate(int dsu[], int depthDsu[], int i) {
    dsu[i] = i;
    depthDsu[i] = 0;
}

int main() {
    int n, m;
    int e1, e2;
    string o;
    cin >> n >> m;

    int dsu[n + 1];
    int depthDsu[n + 1];

    for (int i = 1; i <= n; ++i) {
        setCreate(dsu, depthDsu, i);
    }

    for (int i = 1; i <= m; ++i) {
        cin >> o >> e1 >> e2;
        if (o == "union") {
            make_union(dsu, depthDsu, e1, e2);
        }
        if (o == "get") {
            cout << (repr(dsu, e1) == repr(dsu, e2) ? "YES" : "NO") << endl;
        }
    }


    return 0;
}