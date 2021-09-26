#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, sqrtOfN, nCopy;

    cin >> n;

    nCopy=n;
    sqrtOfN = sqrt(n);

    vector<bool> primes(sqrtOfN + 1, true);
    vector<int> divisers(sqrtOfN + 1, 0);

//    Finding all  primes up to sqrt of given  number
    for (int i = 2; i <= sqrtOfN; ++i) {
        if (primes[i]) {
            for (int j = i * 2; j <= sqrtOfN; j += i) {
                primes[j] = false;
            }
        }
    }

//    Looping through primes to get how many times that prime is in number
    for (int i = 2; i <= sqrtOfN; i++) {
        if (n == 1) {
            break;
        }

        if (primes[i]) {
            while (n % i == 0) {
                n /= i;
                divisers[i]++;
            }
        }
    }

//    Flag for multiplication sign
    bool flag = false;

//    Printing all divisers with their respective count
    for (int i = 2; i <= sqrtOfN; i++) {
        if (divisers[i] > 0) {
            if (flag) {
                cout<<"*";
            }
            flag = true;

            if (divisers[i] == 1) {
                cout << i;
            } else {
                cout << i << "^" << divisers[i];
            }
        }
    }

//    The last multiplier
    if (n>1) {
        if (flag) {
            cout<<"*";
        }
        cout<<n;
    }

    return 0;
}
