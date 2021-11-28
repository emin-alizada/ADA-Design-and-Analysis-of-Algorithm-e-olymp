#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    unsigned int num;


    vector<int> divisors;

    cin >> num;

    for (int i = 1; i <= sqrt(num); ++i) {
        if (num % i == 0) {
//            Add divisors up to square root
            divisors.push_back(i);
        }
    }

//    Add divisors after square root
    for(int i = divisors.size() - 1; i >= 0; i--)
    {
        if (num/divisors[i] != divisors[i]) {
//            To avoid having two times 6 in 36 input sample
            divisors.push_back( num/divisors[i] );
        }
    }

    for (auto &divisor : divisors) // access by reference to avoid copying
    {
        cout << divisor << " ";
    }

    return 0;
}
