#include <iostream>

using namespace std;


int a, b, x;

// Recursive function to return gcd of a and b
long long gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

// function that determines number of positive integers in the interval [1; n], divisible by either a or b
int f(int n) {
    return (n/a) + (n/b) - (n/ lcm(a, b));
}

int binarySearch(int left, int right)
{
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (f(mid) < x) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left;
}


int main() {
//    Binary search week 5, october 22 class
    cin >> a >> b >> x;

//    binary search according to condition of problem
    int res = binarySearch(1, 1000000000);

    cout<< res;

    return 0;
}
