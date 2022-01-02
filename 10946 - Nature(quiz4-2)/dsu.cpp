//
// Created by Emin Alizade on 02.01.22.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
map<string, int> creatures;
vector<int> dsu, depthDsu;
map<int, int> conComp;

int repr(int i) {
//    Path compression heuristic
    if (i == dsu[i]){
        return i;
    }
    return dsu[i] = repr(dsu[i]);
}

void make_union(int a, int b) {
    a = repr(a);
    b = repr(b);

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

int main() {
    while (scanf("%d %d", &n, &m), n + m){
        dsu.resize(n, 0);
        depthDsu.resize(n, 0);

        creatures.clear();
        conComp.clear();

        string t1, t2;
        for (int i = 0; i < n; ++i) {
            cin >> t1;
            creatures[t1] = i;
            dsu[i] = i;
            depthDsu[i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            cin >> t1 >> t2;
            int to = creatures[t1];
            int from = creatures[t2];

            make_union(from, to);
//            make_union(to, from);
        }

        for (int i = 0; i < n; ++i) {
            dsu[i] = repr(i);

            conComp[dsu[i]]++;
        }

        int max = 0;

        for (int i = 0; i < n; ++i) {
            if (conComp[i] > max) {
                max = conComp[i];
            }
        }

        cout << max << endl;
    }

    return 0;
}