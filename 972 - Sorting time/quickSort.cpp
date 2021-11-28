//
// Created by Emin Alizade on 29.10.21.
//

#include <cstdio>
#include <vector>
using namespace std;

int i, n, h, m, s;

struct MyTime
{
    int hour, min, sec;
};

vector<MyTime> lst;

int f(MyTime a, MyTime b)
{
    if ((a.hour == b.hour) && (a.min == b.min)) return a.sec < b.sec;
    if (a.hour == b.hour) return a.min < b.min;
    return a.hour < b.hour;
}

void swap(int &i, int &j)
{
    int temp = i; i = j; j = temp;
}

int Partition(vector<MyTime> &m, int L, int R)
{
    MyTime x = m[L];
    int i = L - 1, j = R + 1;
    while (1)
    {
        do j--; while (f(x,m[j]));
        do i++; while (f(m[i],x));
        if (i < j) swap(m[i], m[j]); else return j;
    }
}

void QuickSort(vector<MyTime> &m, int L, int R)
{
    int q;
    if (L < R)
    {
        q = Partition(m, L, R);
        QuickSort(m, L, q); QuickSort(m, q + 1, R);
    }
}

int main()
{
    scanf("%d", &n);
    lst.resize(n);

    for (i = 0; i < n; i++)
        scanf("%d %d %d", &lst[i].hour, &lst[i].min, &lst[i].sec);

    QuickSort(lst, 0, lst.size() - 1);

    for (i = 0; i < n; i++)
        printf("%d %d %d\n", lst[i].hour, lst[i].min, lst[i].sec);

    return 0;
}