//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<vector<int>> g;
//vector<int> used, topSort;
//bool containsCycle = false;
//
//void dfs(int i) {
//    used[i] = 1;
//    for (int j = 0; j < g[i].size(); j++)
//    {
//        int to = g[i][j];
//
//        // grey vertex - we have a cycle
//        if (used[to] == 1) {
//            containsCycle = true;
//        }
//
//        // if not visited - run dfs
//        if (used[to] == 0) {
//            dfs(to);
//        }
//    }
//    used[i] = 2;
//    topSort.push_back(i);
//}
//
//int main() {
//    int n, m;
//
//    cin >> n >> m;
//    g.resize(n+1);
//    used.resize(n+1,0);
//
//    int a, b;
//    for (int i = 0; i < m; ++i) {
//        cin >> a >> b;
//        g[a].push_back(b);
//    }
//
//    for(int i = 1; i <= n; i++) {
//        if (!used[i]) {
//            dfs(i);
//        }
//    }
//
//    if (containsCycle) {
//        printf("-1");
//    }
//    else {
//        for (int i = n - 1; i >= 0; i--) {
//            printf("%d ", topSort[i]);
//        }
//    }
//
//    return 0;
//}
