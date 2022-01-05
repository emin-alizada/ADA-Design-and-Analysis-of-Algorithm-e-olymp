//#include <iostream>
//
//using namespace std;
//
//int main() {
//    int tests;
//    cin >> tests;
//
//    while (tests--) {
//        int n;
//        cin >> n;
//
//        int m[n];
//
//        for (int i = 0; i < n; ++i) {
//            cin >> m[i];
//        }
//
//        int res = 0;
//        for (int i = 0; i < n - 1; i++) {
//            for (int j = i + 1; j < n; j++) {
//                if (m[i] > m[j]) res++;
//            }
//        }
//
//        cout << "Optimal train swapping takes " << res << " swaps." << endl;
//    }
//    return 0;
//}
