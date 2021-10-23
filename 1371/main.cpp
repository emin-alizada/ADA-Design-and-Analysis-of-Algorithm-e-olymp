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
    int n;
//    Disjoint sets union
//    Even though it's hard to understand from problem itself, it can have several test cases
    while (cin >> n) {
        int e1, e2;
        string o;

        int dsu[1000001];
        int depthDsu[1000001];
        int id[n + 1];
        int maxId = n + 1;
        int yesCounter = 0, noCounter = 0;

        for (int i = 1; i <= 1000000; ++i) {
            setCreate(dsu, depthDsu, i);
        }

        for (int i = 1; i <= n; ++i) {
            id[i] = i;
        }

        cin >> o;
        while (o != "e") {
            if (o == "c") {
                cin >> e1 >> e2;
                make_union(dsu, depthDsu, id[e1], id[e2]);
            }
            if (o == "q") {
                cin >> e1 >> e2;
                if ( repr(dsu, id[e1]) == repr(dsu, id[e2]) ) {
                    yesCounter++;
                } else {
                    noCounter++;
                }
            }
            if (o == "d") {
                cin >> e1;
                id[e1] = maxId;
                maxId++;
            }
            cin >> o;
        }

        cout << yesCounter << " , " << noCounter << endl;
    }

    return 0;
}