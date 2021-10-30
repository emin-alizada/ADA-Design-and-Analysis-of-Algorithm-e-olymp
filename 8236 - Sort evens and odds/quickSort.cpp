//
// Created by Emin Alizade on 30.10.21.
//

#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

int comparator(int a, int b) {
    if (abs(a % 2) != abs(b % 2))
        return abs(a % 2) < abs(b % 2);
    if (a % 2 == 0)
        return a < b;
    if (abs(a % 2) == 1)
        return a > b;
}

int Partition(int m[], int L, int R)
{
    int x = m[L];
    int i = L - 1, j = R + 1;
    while (1)
    {
        do j--; while (comparator(m[j], x));
        do i++; while (comparator(x,m[i]));
        if (i < j) swap(m[i], m[j]); else return j;
    }
}

void quickSort(int m[], int L, int R)
{
    int q;
    if (L < R)
    {
        q = Partition(m, L, R);
        quickSort(m, L, q);
        quickSort(m, q + 1, R);
    }
}

void printArray(int a[], int n) {
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
//    cout << endl;
}

int main() {
    int n, temp;

    cin >> n;

    int a[n + 1];

    for (int i = 1; i <= n; ++i) {
        cin>>temp;
        a[i] = temp;
    }

    quickSort(a, 1, n);

    printArray(a, n);

    return 0;
}