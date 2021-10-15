#include <iostream>

using namespace std;

//#define MAX 1001
//int a[MAX];

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

//void heapify(int a[], int i, int n) { // n = size of heap
//    for (int j = 1; j <= n; ++j) {
//        cout << a[j] << " ";
//    }
//    cout<< endl;
//    int largest = 0;
//    int l = left(i);
//    int r = right(i);
//
//    if ( !(r > n || l > n) ) {
//        largest = a[l] > a[i] ? l : i;
//        largest = a[r] > a[i] ? r : i;
//
//        if (largest != i) {
//            swap(a[i], a[largest]);
//            heapify(a, largest, n);
//        }
//    }
//}

void heapify(int a[], int i, int n) // n = size of a heap
{
//    cout << a[i] << endl;
//    for (int j = 1; j <= n; ++j) {
//        cout << a[j] << " ";
//    }
//    cout<<endl;
    int largest = 0;
    int l = left(i);
    int r = right(i);

    if (l <= n && a[l] > a[i])
    {
        largest = l;
    }
    else {
        largest = i;
    }
    if (r <= n && a[r] > a[largest]) {
        largest = r;
    }

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, largest, n);
    }
}

int main() {
    int n, temp;
    cin >> n;

    int a[n + 1];

    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        a[i] = temp;
    }

    for (int i = n/2; i > 0; --i) {
        heapify(a, i, n);
    }

    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }

    return 0;
}
