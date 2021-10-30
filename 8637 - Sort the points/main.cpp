#include <iostream>
#include <vector>

using namespace std;

struct MyPoint {
    MyPoint(int a, int b) {
        x = a;
        y = b;
    }

    int x, y;
};

int comparator(MyPoint a, MyPoint b) {
    int sumA = a.x + a.y;
    int sumB = b.x + b.y;

    if (sumA == sumB) {
        return a.x < b.x;
    }
    return sumA < sumB;
}

int Partition(vector<MyPoint> &m, int L, int R)
{
    MyPoint x = m[L];
    int i = L - 1, j = R + 1;
    while (1)
    {
        do j--; while (comparator(x,m[j]));
        do i++; while (comparator(m[i],x));
        if (i < j) swap(m[i], m[j]); else return j;
    }
}

void quickSort(vector<MyPoint> &m, int L, int R)
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
    int x,y;
    vector<MyPoint> a;

    while (cin >> x>>y) {
        a.push_back(MyPoint(x, y));
    }

    quickSort(a, 0 , a.size() - 1);

    for (int i = 0; i < a.size(); ++i) {
        cout << a[i].x << " " << a[i].y << endl;
    }

    return 0;
}
