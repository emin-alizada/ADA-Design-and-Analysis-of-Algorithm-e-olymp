//#include <iostream>
//
//using namespace std;
//
//struct MyTime {
//    int hour, min, sec;
//    MyTime() {};
//    MyTime(MyTime *a) {
//        hour = a->hour;
//        min = a->min;
//        sec = a->sec;
//    };
//    MyTime(int h, int m, int s) {
//        hour = h;
//        min = m;
//        sec = s;
//    }
//};
//
//int comparator (MyTime a, MyTime b) {
//    if (a.hour == b.hour && a.min == b.min) {
//        return a.sec < b.sec;
//    }
//    if (a.hour == b.hour ) {
//        return a.min < b.min;
//    }
//    return a.hour < b.hour;
//}
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
//void heapify(MyTime a[], int i, int n) {
//    int largest = 0;
//    int l = left(i);
//    int r = right(i);
//
//    if (l <= n && comparator(a[i], a[l])) {
//        largest = l;
//    } else {
//        largest = i;
//    }
//    if (r <= n && comparator(a[largest], a[r]) ) {
//        largest = r;
//    }
//
//    if (largest != i) {
//        swap(a[i], a[largest]);
//        heapify(a, largest, n);
//    }
//}
//
//void buildHeap(MyTime a[], int n) {
//    for (int j = n / 2; j > 0; --j) {
//        heapify(a, j, n);
//    }
//}
//
//void printArray(MyTime a[], int n) {
//    for (int i = 1; i <= n; ++i) {
//        cout << a[i].hour << " " << a[i].min << " " << a[i].sec << endl;
//    }
//}
//
//void heapSort(MyTime a[], int n) {
//    for (int i = n; i > 1 ; --i) {
//        swap(a[1], a[i]);
//        heapify(a, 1, i-1);
//    }
//}
//
//int main() {
//    int n, h,m,s;
//
//    cin >> n;
//
//    MyTime a[n + 1];
//
//    for (int i = 1; i <= n; ++i) {
//        cin >> h >> m >> s;
//        a[i] = new MyTime(h, m, s);
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