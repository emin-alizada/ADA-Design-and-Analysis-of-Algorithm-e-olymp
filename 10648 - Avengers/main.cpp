//
// Created by Emin Alizade on 20.12.21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> g;
vector<int> InDegree, topSort;
queue<int> q;
bool flag = false;

int main() {
    int n, m;

    cin >> n >> m;
    g.resize(n+1);
    InDegree.assign(n + 1, 0);

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        InDegree[b]++;
    }

    for (int i = 1; i < InDegree.size(); i++) {
        if (InDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        if (q.size() >= 2) {
            flag = true;
            break;
        }

        int v = q.front();
        q.pop();
        topSort.push_back(v);
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            InDegree[to]--;
            if (InDegree[to] == 0) {
                q.push(to);
            }
        }
    }


//    If it's possible or not
    if (n < 3 || !flag) {
        cout << -1;
    }
    else {
//        Emptying queue into the vector
        vector<int> temp;
        while (!q.empty()) {
            temp.push_back(q.front());
            q.pop();
        }

//        if length is more than 2, then vector is enough
        if (temp.size() > 2) {
            for (int i = 0; i < 3; ++i) {
                cout << temp[i] << " ";
            }
        } else {
            for (int i = 0; i < temp.size(); ++i) {
                cout << temp[i] << " ";
            }

//            Otherwise we add a third node
            if (find(temp.begin(), temp.end(), 1) == temp.end()) {
                cout << 1;
            } else if (find(temp.begin(), temp.end(), 2) == temp.end()) {
                cout << 2;
            } else if (find(temp.begin(), temp.end(), 3) == temp.end()) {
                cout << 3;
            } else {
                cout << 4;
            }
        }
    }

    return 0;
}
