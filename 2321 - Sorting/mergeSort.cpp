////
//// Created by Emin Alizade on 23.10.21.
////
//
////
//// Created by Emin Alizade on 23.10.21.
////
//
//#include <iostream>
//
//using namespace std;
//
//void printArray(int a[], int n) {
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << " ";
//    }
//    cout << endl;
//}
//
//void mergeOfSort(int a[], int lb, int le, int rb, int re) {
////    lb - left begin, le - left end, rb - right begin, re - right end
//// a[lb..le] and a[rb..re] are merged into a[lb..re]
//
//    int lp = lb; // left pointer
//    int rp = rb; // right pointer
//    int len = re - lp + 1;
//
//    int i;
//    int res[len]; // temporary array
//
//    for (i = 0; lp <= le && rp <= re; i++) {
//        if (a[lp] < a[rp]) {
//            res[i] = a[lp];
//            lp++;
//        } else {
//            res[i] = a[rp];
//            rp++;
//        }
//    }
//
////    rest of left part
//    while (lp <= le) {
//        res[i] = a[lp];
//        lp++;
//        i++;
//    }
//
////    rest of right part
//    while (rp <= re) {
//        res[i] = a[rp];
//        rp++;
//        i++;
//    }
//
//    for (int j = 0; j < len; ++j) {
//        a[lb + j] = res[j];
//    }
//}
//
//void mergeSort(int a[], int left, int right) {
//    if (left >= right) {
//        return;
//    }
//
//    int mid = (left + right) / 2;
//
//    mergeSort(a, left, mid);
//    mergeSort(a, mid + 1, right);
//    mergeOfSort(a, left, mid, mid + 1, right);
//}
//
//int main() {
////    stl merge function
//    int n;
//    cin >> n;
//
//    int a[n];
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//
//    mergeSort(a, 0, n-1);
//
//    printArray(a, n);
//
//    return 0;
//}