#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int a[n];

    int min = INT32_MAX;
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        int rangeBegin = i - k + 1;
        if (index < rangeBegin)
        {
            min = a[rangeBegin];
            for (int j = rangeBegin; j <= i; j++)
                if (min >= a[j]) {
                    min = a[j];
                    index = j;
                }
        }
        if (min >= a[i]){
            min = a[i];
            index = i;
        }

        if (i + 1 >= k) {
            cout << min << " ";
        }
    }
}