#include <iostream>
#define MAX 100001


using namespace std;

int sz, x[MAX], lis[MAX], L[MAX];


void PrintSeq(int pos)
{
    if (sz < 0) return;
    while (L[pos] != sz) {
        pos--;
    }

    sz--;
    PrintSeq(pos - 1);
    printf("%d ", x[pos]);
}

//Week 9: November 19 - Longest Increasing Subsequence (LIS)
int main() {
    int n;
    cin >> n;


    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    int len, i;
//    create solitare layout
    for (len = i = 0; i < n; i++)
    {
        int pos = lower_bound(lis,lis+len,x[i]) - lis;
        lis[pos] = x[i];
        L[i] = pos;
        if (pos == len)
            len++;
    }

    cout << len << endl;

    sz = len - 1;
    PrintSeq(n - 1);

    return 0;
}
