#include <iostream>
#include <cmath>

using namespace std;

int modExpo(long long number, unsigned int  power, int mod)
{
    int result = 1;
    number = number % mod; // Update number if it is more than or
    // equal to mod

    if (number == 0) return 0;

    while (power > 0)
    {
        // If power is odd, multiply number with result
        if (power % 2 == 1) {
            result = (result*number) % mod;
        }
        // power must be even now
        power = power / 2;
        number = (number*number) % mod;
    }
    return result;
}

int main() {
    long long numberOfBinsOrBalls;
    long long modulo = pow(10,9) + 7;

    cin >> numberOfBinsOrBalls;

//    in order to prevent the case where we call modExpo function with 0 value
    if (numberOfBinsOrBalls > 1) {
        long long result = ((numberOfBinsOrBalls % modulo) * modExpo(numberOfBinsOrBalls - 1, numberOfBinsOrBalls-1, modulo)) % modulo;

        cout << result;
    } else {
        cout<<1;
    }

    return 0;
}
