#include <iostream>
#include <vector>

using namespace std;



int main() {
    long long n, m, i, j;

    cin >> n >> m;

    vector<long long> cat(n+1, 0);

    cat[0] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < i; j++)
            cat[i] = (cat[i] + cat[j] * cat[i - j - 1]) % m;
    }

    cout << cat[n];

    return 0;
}
