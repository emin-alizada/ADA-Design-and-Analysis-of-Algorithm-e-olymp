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
//void heapify(int a[], int i, int n) {
//    int largest = 0;
//    int l = left(i);
//    int r = right(i);
//
//    if (l <= n && a[l] > a[i]) {
//        largest = l;
//    } else {
//        largest = i;
//    }
//    if (r <= n && a[r] > a[largest]) {
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
//    for (int j = n / 2; j > 0; --j) {
//        heapify(a, j, n);
//    }
//}
//
//void printArray(int a[], int n) {
//    for (int i = 1; i <= n; ++i) {
//        cout << a[i] << " ";
//    }
//    cout << endl;
//}
//
//void heapSort(int a[], int n) {
//    for (int i = n; i > 1 ; --i) {
//        swap(a[1], a[i]);
//        heapify(a, 1, i-1);
//    }
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
//        cin >> temp;
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
