#include <iostream>
#include <vector>


using namespace std;

int repr(int dsu[], int i) {
//    Path compression heuristic
    if (i == dsu[i]){
        return i;
    }
    return dsu[i] = repr(dsu, dsu[i]);
}

bool isInTheSameSet(int dsu[], int a, int b) {
    return repr(dsu, a) == repr(dsu, b);
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
    int n, m, numberOfOperations;
    int e1, e2;
    cin >> n >> m >> numberOfOperations;

    int dsu[n + 1];
    int depthDsu[n + 1];

    for (int i = 1; i <= n; ++i) {
        setCreate(dsu, depthDsu, i);
    }

//    We don't need it
    for (int i = 1; i <= m; ++i) {
        cin >> e1 >> e2;
    }

    string opCode;
    vector<pair<string, pair<int, int>>> ope;
    vector<string> res;

    for (int i = 0; i < numberOfOperations; ++i) {
        cin >> opCode >> e1 >> e2;
        ope.push_back(make_pair(opCode, make_pair(e1,e2)));
    }

    for (int i = numberOfOperations - 1; i >= 0; --i) {
        opCode = ope[i].first;
        e1 = ope[i].second.first;
        e2 = ope[i].second.second;
        if (opCode == "ask") {
            if (isInTheSameSet(dsu, e1, e2)) {
                res.push_back("YES");
            } else {
                res.push_back("NO");
            }
        } else if(opCode == "cut") {
            make_union(dsu, depthDsu, e1, e2);
        }
    }

    for (int i = res.size() - 1; i >=0; --i) {
        cout << res[i] << endl;
    }

    return 0;
}