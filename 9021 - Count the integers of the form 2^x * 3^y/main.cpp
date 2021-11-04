#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long MAXI = pow(10, 18);

// To store all valid integers
vector<long long> v;

// Function to find all the integers of the
// form (2^x * 3^y) in the range [0, 1-^18]
void precompute()
{

    // To store powers of 2 and 3
    // initialized to 2^0 and 3^0
    long long x = 1, y = 1;

    // While current power of 2
    // is within the range
    while (x <= MAXI && x >=0) {

        // While number is within the range
        while (x * y <= MAXI && x*y >=0) {

            // Add the number to the vector
            v.push_back(x * y);

            // Next power of 3
            y *= 3;
        }

        // Next power of 2
        x *= 2;

        // Reset to 3^0
        y = 1;
    }

    // Sort the vector
    sort(v.begin(), v.end());
}

// Function to find the count of numbers
// in the range [l, r] which are
// of the form (2^x * 3^y)
void countNum(long long l, long long r)
{
    cout << upper_bound(v.begin(), v.end(), r)
            - upper_bound(v.begin(), v.end(), l - 1) << endl;
}

//Count the integers of the form 2^x * 3^y
int main()
{
    // Pre-compute all the valid numbers
    precompute();

    long long l, r;

    while (cin>>l>>r) {
        countNum(l, r);
    }


    return 0;
}