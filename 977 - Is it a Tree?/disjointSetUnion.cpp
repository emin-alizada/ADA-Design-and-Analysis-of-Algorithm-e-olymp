////
//// Created by Emin Alizade on 03.12.21.
////
//
//#include <iostream>
//
//using namespace std;
//
//int repr(int dsu[], int i) {
////    Path compression heuristic
//    if (i == dsu[i]) {
//        return i;
//    }
//    return dsu[i] = repr(dsu, dsu[i]);
//}
//
//void make_union(int dsu[], int depthDsu[], int a, int b) {
//    a = repr(dsu, a);
//    b = repr(dsu, b);
//
//    if (a == b) {
//        return;
//    } else {
//        if (depthDsu[a] > depthDsu[b]) {
//            swap(a, b);
//        }
//        dsu[a] = b;
//        if (depthDsu[a] == depthDsu[b]) {
//            depthDsu[b]++;
//        }
//    }
//}
//
//void setCreate(int dsu[], int depthDsu[], int i) {
//    dsu[i] = i;
//    depthDsu[i] = 0;
//}
//
//int numberOfSets(int dsu[], int n) {
//    int count = 0;
//    for (int i = 1; i <= n; ++i) {
//        if (i == dsu[i]) {
//            count++;
//        }
//    }
//    return count;
//}
//
//// Week 11: November 29 - December 5 - DSU (Disjoint set union)
//int main() {
//    int n, temp, countEdges = 0;
//    cin >> n;
//
//    int dsu[n + 1];
//    int depthDsu[n + 1];
//
//    for (int i = 1; i <= n; ++i) {
//        setCreate(dsu, depthDsu, i);
//    }
//
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            cin >> temp;
//            if (temp == 1) {
//                make_union(dsu, depthDsu, i, j);
//                countEdges++;
//            }
//        }
//    }
//
//    if (countEdges / 2 == n - 1 && numberOfSets(dsu, n) == 1) {
//        cout << "YES";
//    } else {
//        cout << "NO";
//    }
//
//    return 0;
//}
