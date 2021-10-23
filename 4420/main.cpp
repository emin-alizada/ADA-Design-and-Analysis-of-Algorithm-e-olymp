#include <iostream>
#define EPS 1e-12
using namespace std;

int a,b,c,d;

double f(double x) {
    return (a * x * x * x) + ( b * x * x ) + (c * x) + d;
}

int main() {
    cin >> a >> b >> c >> d;

    double left, right = 1, middle;

    while ( f(right) * f(-right) >= 0 ) {
        right*=2;
    }

    left = -right;

    while (right - left > EPS) {
        middle = (left + right) / 2;

        if (f(middle) * f(right) > 0) {
            right = middle;
        }
        else {
            left = middle;
        }
    }

    printf("%lf\n", left);

    return 0;
}
