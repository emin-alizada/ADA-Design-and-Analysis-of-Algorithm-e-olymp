#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//Almost Prime Numbers
int main() {
    long long almostMax = 1e12;
    long long primesMax = 1e6;

    int primes[primesMax+1];
    vector<long long> almost;

    // sieve of eratosthenes for generating primes
    for(int i = 0; i < primesMax; i++) {
        primes[i] = 1;
    }

    for(int i = 2; i < sqrt(primesMax); i++) {
        if (primes[i]) {
            for (int j = i * i; j <= primesMax; j += i) {
                primes[j] = 0;
            }
        }
    }
//    end of sieve of eratosthenes


//  Generating almost primes
    for (int i = 2; i <= primesMax; ++i) {
        if (primes[i]) {
            long long temp = i;
            while ((temp *= i) <= almostMax) {
                almost.push_back(temp);
            }
        }
    }

//    Sorting it for binary search
    sort(almost.begin(), almost.end());


//    Main Part read data and output accordingly

    int n;
    long long a, b;
    cin >> n;

    while (n--) {
        cin >> a >> b;
        cout << upper_bound(almost.begin(), almost.end(), b)
                - upper_bound(almost.begin(), almost.end(), a-1) << endl;
    }

    return 0;
}
