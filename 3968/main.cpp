#include <iostream>
#include <math.h>

#define EPS 1e-10

using namespace std;

double f(double x) {
    return x * x + sqrt(x);
}

int main() {
    double c;
    cin >> c;

    double left = 0, right = c, middle;
    double y;

    while (right - left > EPS) {
        middle = (left + right) / 2;
        y = f(middle);
        if (y > c) {
            right = middle;
        }
        else {
            left = middle;
        }
    }

    printf("%lf\n",left);
    return 0;
}
