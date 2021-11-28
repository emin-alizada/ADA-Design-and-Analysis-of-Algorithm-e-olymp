#include <iostream>

using namespace std;

int repr(int dsu[], int i) {
//    Path compression heuristic
    if (i == dsu[i]){
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
//        Rank heuristic
        if (depthDsu[a] > depthDsu[b]) {
            swap(a, b);
        }
        dsu[a] = b;
        if (depthDsu[a] == depthDsu[b]) {
            depthDsu[b]++;
        }
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

void setCreate(int dsu[], int depthDsu[], int i) {
    dsu[i] = i;
    depthDsu[i] = 0;
}

int main() {
    int n, s, m;
    int e1, e2;
    cin >> n >> s >> m;

    int dsu[n + 1];
    int depthDsu[n + 1];

    for (int i = 1; i <= n; ++i) {
        setCreate(dsu, depthDsu, i);
    }

    for (int i = 1; i <= m; ++i) {
        cin >> e1 >> e2;
        make_union(dsu, depthDsu, e1, e2);
    }

    cout << (numberOfSets(dsu, n) - 1 );
    return 0;
}