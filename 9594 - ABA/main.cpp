#include <iostream>

using namespace std;

int main() {
    string a;
    cin >> a;

    unsigned long long length = a.size();
    unsigned long long na[length]; // number of a in each position

    for (unsigned long long i = 0; i < length; ++i) {
        na[i] = 0; //initially setting to zero
    }

    for (unsigned long long i = 0; i < length; ++i) {
        na[i] = i == 0 ? 0 : na[i-1]; // each na[i] is equal to previous

        if (a[i] == 'A') {
            na[i]++; // if the char is a, the number of a up to this point ++
        }
    }

    unsigned long long res = 0;

    for (unsigned long long i = 0; i < length; ++i) {
        if (a[i] == 'B') {
//            To find out how many ABA strings is there we, look for each B in strng and multiply number of a before that b and after that b
            res += na[i] * (na[length - 1] - na[i]);
        }
    }

    cout << res;

    return 0;
}
