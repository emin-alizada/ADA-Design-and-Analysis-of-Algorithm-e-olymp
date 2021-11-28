#include <iostream>
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
    int number, power, mod;

    cin >> number >> power >> mod;

    int result = modExpo(number, power, mod);

    cout << result;

    return 0;
}
