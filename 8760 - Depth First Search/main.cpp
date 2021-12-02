//#include <iostream>
//#define MAX 101
//
//using namespace std;
//
//int g[MAX][MAX], used[MAX], n, m;
//
//void dfsMatrix(int v) {
//    cout << v << " ";
//    used[v] = 1;
//
//    for (int i = 1; i <= n; ++i) {
//        if (used[i] == 0 && g[v][i] == 1) {
//            dfsMatrix(i);
//        }
//    }
//}
//
//int main() {
//    cin >> n >> m;
//
//    int a, b, v;
//    for (int i = 1; i <= m; ++i) {
//        cin >> a >> b;
//
//        g[a][b] = 1;
//        g[b][a] = 1;
//    }
//
//    cin >> v;
//
//    dfsMatrix(v);
//
//    return 0;
//}
