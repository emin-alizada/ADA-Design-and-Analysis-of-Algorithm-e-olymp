//#include <iostream>
//
//using namespace std;
//
//int repr(int dsu[], int i) {
//    int r = dsu[i];
//    while (r != dsu[r]){
//        r = dsu[r];
//    }
//    return r;
//}
//
//void make_union(int dsu[], int a, int b) {
//    a = repr(dsu, a);
//    b = repr(dsu, b);
//
//    if (a == b) {
//        return;
//    } else {
//        dsu[a] = b;
//    }
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
//int main() {
//    int n, temp;
//    cin >> n;
//
//    int dsu[n + 1];
//
//    for (int i = 1; i <= n; ++i) {
//        dsu[i] = i;
//    }
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cin >> temp;
//            if (temp == 1) {
//                make_union(dsu, i+1, j+1);
//            }
//        }
//    }
//
//    cout << numberOfSets(dsu, n);
//    return 0;
//}
