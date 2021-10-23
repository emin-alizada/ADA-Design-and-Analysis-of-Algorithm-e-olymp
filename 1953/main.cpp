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
//        return a.orderNumber > b.orderNumber;
//    }
//    return a.score < b.score;
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
//void swap(Participant &a, Participant &b) {
//    Participant c = a;
//    a = b;
//    b = c;
//}
//
//void heapify(Participant a[], int i, int n) {
//    int largest = 0;
//    int l = left(i);
//    int r = right(i);
//
//    if (l <= n && comparator(a[l], a[i])) {
//        largest = l;
//    } else {
//        largest = i;
//    }
//    if (r <= n && comparator(a[r], a[largest]) ) {
//        largest = r;
//    }
//
//    if (largest != i) {
//        swap(a[i], a[largest]);
//        heapify(a, largest, n);
//    }
//}
//
//void printArray(Participant a[], int n) {
//    for (int i = 1; i <= n; ++i) {
//        cout << a[i].orderNumber << " ";
//    }
//    cout<<endl;
//}
//
//void buildHeap(Participant a[], int n) {
//    for (int j = n / 2; j > 0; --j) {
//        heapify(a, j, n);
//    }
////    printArray(a, n);
//}
//
//void heapSort(Participant a[], int n) {
//    for (int i = n; i > 1 ; --i) {
//        swap(a[1], a[i]);
//        heapify(a, 1, i-1);
//    }
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
//    buildHeap(a, n);
//
//    heapSort(a, n);
//
//    printArray(a, n);
//
//    return 0;
//}
//
////3
////222 222 221