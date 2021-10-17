#include <iostream>

using namespace std;

int repr(int dsu[], int i) {
//    Path compression heuristic
    if (i == dsu[i]) {
        return i;
    }
    return dsu[i] = repr(dsu, dsu[i]);
}

void make_union(int dsu[], int depthDsu[], int min[], int max[], int num[], int a, int b) {
    a = repr(dsu, a);
    b = repr(dsu, b);

    if (a == b) {
        return;
    } else {
        if (depthDsu[a] > depthDsu[b]) {
            swap(a, b);
        }
        dsu[a] = b;
//        When makin union we are adjusting new leader min, max and num accordingly
        if (depthDsu[a] == depthDsu[b]) {
            depthDsu[b]++;
        }
        if (min[a] < min[b]) {
            min[b] = min[a];
        }
        if (max[a] > max[b]) {
            max[b] = max[a];
        }
        num[b] += num[a];
    }
}

void setCreate(int dsu[], int depthDsu[], int min[], int max[], int num[], int i) {
//    When creating set min, max is the i th number itself, number of elements 1
    dsu[i] = i;
    depthDsu[i] = 0;
    min[i] = i;
    max[i] = i;
    num[i] = 1;
}

int main() {
    int n, m;
    int e1, e2;
    string o;
    cin >> n >> m;

    int dsu[n + 1];
    int depthDsu[n + 1];
    int min[n + 1];
    int max[n + 1];
    int num[n + 1];

    for (int i = 1; i <= n; ++i) {
        setCreate(dsu, depthDsu, min, max, num, i);
    }

    for (int i = 1; i <= m; ++i) {
        cin >> o;
        if (o == "union") {
            cin >> e1 >> e2;
            make_union(dsu, depthDsu, min, max, num, e1, e2);
        }
        if (o == "get") {
            cin >> e1;
            int r = repr(dsu, e1);
            cout << min[r] << " " << max[r] << " " << num[r] << endl;
        }
    }


    return 0;
}