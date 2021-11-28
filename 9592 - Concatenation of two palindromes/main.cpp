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

long long waysOfCreatingPalindromeModuled(int lengthOfString, short numberOfLettersInAlphabet, int module) {
    int powerValue = (lengthOfString + 1) / 2;

    return modExpo(numberOfLettersInAlphabet, powerValue, module);
}

int main() {
    int lengthOfPalindrome;
    short numberOfLettersInAlphabet;
    int moduloValue = pow(10, 9) + 7;
    long long result = 0;

    cin >> lengthOfPalindrome >> numberOfLettersInAlphabet;

    for (int i = 1; i < lengthOfPalindrome; ++i) {
        long long leftPart = waysOfCreatingPalindromeModuled(i, numberOfLettersInAlphabet, moduloValue) % moduloValue;
        long long rightPart = waysOfCreatingPalindromeModuled(lengthOfPalindrome - i, numberOfLettersInAlphabet, moduloValue) % moduloValue;

        result += (leftPart * rightPart) % moduloValue;
        result = result % moduloValue;
    }

    cout << result;

    return 0;
}
