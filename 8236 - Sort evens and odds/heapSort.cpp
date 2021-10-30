//#include <iostream>
//
//using namespace std;
//
//int left(int i) {
//    return 2 * i;
//}
//
//int right(int i) {
//    return 2 * i + 1;
//}
//
//void swap(int &a, int &b) {
//    int c = a;
//    a = b;
//    b = c;
//}
//
//int comparator(int a, int b) {
//    if (abs(a % 2) != abs(b % 2))
//        return abs(a % 2) < abs(b % 2);
//    if (a % 2 == 0)
//        return a < b;
//    if (abs(a % 2) == 1)
//        return a > b;
//}
//
//void heapify(int a[], int i, int n) {
//    int largest = 0;
//    int l = left(i);
//    int r = right(i);
//
//    if (l<=n && comparator(a[l], a[i]) ) {
//        largest = l;
//    } else {
//        largest = i;
//    }
//
//    if (r<=n && comparator( a[r], a[largest] )) {
//        largest = r;
//    }
//
//    if (largest != i) {
//        swap(a[i], a[largest]);
//        heapify(a, largest, n);
//    }
//}
//
//void buildHeap(int a[], int n) {
//    for (int i = n/2; i > 0; --i) {
//        heapify(a, i, n);
//    }
//}
//
//void heapSort(int a[], int n) {
//    for (int i = n; i > 0; --i) {
//        swap(a[1], a[i]);
//        heapify(a, 1, i-1);
//    }
//}
//
//void printArray(int a[], int n) {
//    for (int i = 1; i <= n; ++i) {
//        cout << a[i] << " ";
//    }
////    cout << endl;
//}
//
//int main() {
//    int n, temp;
//
//    cin >> n;
//
//    int a[n + 1];
//
//    for (int i = 1; i <= n; ++i) {
//        cin>>temp;
//        a[i] = temp;
//    }
//
//    buildHeap(a, n);
//
//    heapSort(a, n);
//
//    printArray(a, n);
//
//    return 0;
//}