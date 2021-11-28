//
// Created by Emin Alizade on 30.10.21.
//


#include <iostream>

using namespace std;

struct Participant {
    int score, orderNumber;
    Participant() {};
    Participant(Participant *a) {
        score = a->score;
        orderNumber = a->orderNumber;
    };
    Participant(int s, int n) {
        score = s;
        orderNumber = n;
    }
};

int comparator (Participant a, Participant b) {
    if (a.score == b.score) {
        return a.orderNumber < b.orderNumber;
    }
    return a.score > b.score;
}

void printArray(Participant a[], int n) {
    for (int i = 1; i <= n; ++i) {
        cout << a[i].orderNumber << " ";
    }
    cout<<endl;
}

int Partition(Participant m[], int L, int R)
{
    Participant x = m[L];
    int i = L - 1, j = R + 1;
    while (1)
    {
        do j--; while (comparator(x,m[j]));
        do i++; while (comparator(m[i],x));
        if (i < j) swap(m[i], m[j]); else return j;
    }
}

void quickSort(Participant m[], int L, int R)
{
    int q;
    if (L < R)
    {
        q = Partition(m, L, R);
        quickSort(m, L, q);
        quickSort(m, q + 1, R);
    }
}


int main() {
    int n, score;

    cin >> n;

    Participant a[n + 1];

    for (int i = 1; i <= n; ++i) {
        cin >> score;
        a[i] = new Participant(score, i);
    }

    quickSort(a, 1, n);

    printArray(a, n);

    return 0;
}