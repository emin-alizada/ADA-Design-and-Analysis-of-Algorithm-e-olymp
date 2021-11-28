//
// Created by Emin Alizade on 23.10.21.
//
//
//#include <iostream>
//
//using namespace std;
//
//struct Participant {
//    int score, orderNumber;
//    Participant() {};
//    Participant(Participant *a) {
//        score = a->score;
//        orderNumber = a->orderNumber;
//    };
//    Participant(int s, int n) {
//        score = s;
//        orderNumber = n;
//    }
//};
//
//int comparator (Participant a, Participant b) {
//    if (a.score == b.score) {
//        return a.orderNumber < b.orderNumber;
//    }
//    return a.score > b.score;
//}
//
//void printArray(Participant a[], int n) {
//    for (int i = 1; i <= n; ++i) {
//        cout << a[i].orderNumber << " ";
//    }
//    cout<<endl;
//}
//
//void mergeOfSort(Participant a[], int lb, int le, int rb, int re) {
////    lb - left begin, le - left end, rb - right begin, re - right end
//// a[lb..le] and a[rb..re] are merged into a[lb..re]
//
//    int lp = lb; // left pointer
//    int rp = rb; // right pointer
//    int len = re - lp + 1;
//
//    int i;
//    Participant res[len]; // temporary array
//
//    for (i = 0; lp <= le && rp <= re; i++) {
//        if ( comparator(a[lp], a[rp]) ) {
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
//void mergeSort(Participant a[], int left, int right) {
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
//    int n, score;
//
//    cin >> n;
//
//    Participant a[n + 1];
//
//    for (int i = 1; i <= n; ++i) {
//        cin >> score;
//        a[i] = new Participant(score, i);
//    }
//
//    mergeSort(a, 1, n);
//
//    printArray(a, n);
//
//    return 0;
//}