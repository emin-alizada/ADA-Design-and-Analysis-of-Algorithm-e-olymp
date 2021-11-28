//
// Created by Emin Alizade on 29.10.21.
//

#include <cstdio>
#include <vector>
using namespace std;

int i, n;

vector<int> lst;

void swap(int &i, int &j)
{
    int temp = i; i = j; j = temp;
}

int Partition(vector<int> &m, int L, int R)
{
    int x = m[L];
    int i = L - 1, j = R + 1;
    while (1)
    {
        do j--; while (x > m[j]);
        do i++; while (m[i] > x);
        if (i < j) swap(m[i], m[j]); else return j;
    }
}

void QuickSort(vector<int> &m, int L, int R)
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
        scanf("%d", &lst[i]);

    QuickSort(lst, 0, lst.size() - 1);

    for (i = n-1; i >= 0; i--)
        printf("%d ", lst[i]);

    return 0;
}