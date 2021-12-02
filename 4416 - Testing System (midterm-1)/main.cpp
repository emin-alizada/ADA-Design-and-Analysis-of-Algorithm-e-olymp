#include <iostream>

// 4416 - Testing System
using namespace std;

int a[100001][3];

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

int f(int i, int j) {
    if (a[i][0] == a[j][0] && a[i][1] == a[j][1]) {
        return a[i][2] > a[j][2];
    } else if (a[i][0] == a[j][0]) {
        return a[i][1] > a[j][1];
    } else {
        return a[i][0] < a[j][0];
    }
}

void heapify(int i, int n) {
    int largest = 0;
    int l = left(i);
    int r = right(i);

    if (l <= n && f(l,i)) {
        largest = l;
    } else {
        largest = i;
    }
    if (r <= n && f(r, largest)) {
        largest = r;
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(largest, n);
    }
}

void buildHeap(int n) {
    for (int j = n / 2; j > 0; --j) {
        heapify(j, n);
    }
}

void printArray(int n) {
    for (int i = 1; i <= n; ++i) {
        cout << a[i][2] << " ";
    }
    cout << endl;
}

void heapSort(int n) {
    for (int i = n; i > 1 ; --i) {
        swap(a[1], a[i]);
        heapify(1, i-1);
    }
}

int main() {
    int n, solved, pen;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> solved >> pen;
        a[i][0] = solved;
        a[i][1] = pen;
        a[i][2] = i;
    }

    buildHeap(n);

    heapSort( n);

    printArray(n);

    return 0;
}
