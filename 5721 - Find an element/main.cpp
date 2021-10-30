#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, k, i;

int Partition(int left, int right)
{
//    key to success is to take x as median
    int x = (v[left] + v[right])/2, i = left - 1, j = right + 1;
    while (1)
    {
        do j--; while (v[j] > x);
        do i++; while (v[i] < x);
        if (i < j) swap(v[i], v[j]); else return j;
    }
}

int kth(int k, int left, int right)
{
    if (left == right) return v[left];
    int pos = Partition(left, right);
    if (k <= pos) return kth(k, left, pos);
    else return kth(k, pos + 1, right);
}

int main(void)
{
    scanf("%d %d", &n, &k);
    v.resize(n + 1);
    for (i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    if (k>n || k < 0) {
        printf("%d", -1);
    } else {
        printf("%d\n", kth(n-k + 1, 1, n));
    }

    return 0;
}