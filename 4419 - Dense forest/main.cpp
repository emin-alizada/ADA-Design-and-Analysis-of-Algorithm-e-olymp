#include <iostream>
#include <math.h>
#define EPS 1e-9

using namespace std;

double vp, vf, oy;

// square function
double s(double x) {
    return x * x;
}

double t(double x)
{
    return sqrt(s(x) + s(1 - oy)) / vp + sqrt(s(oy) + s(1 - x)) / vf;
}

int main() {
    cin >> vp >> vf >> oy;
    double left = 0, right = 1;

    double f, g; // points for ternary search

    while (right - left >= EPS) {
        f = left + (right - left) / 3;
        g = right - (right - left) / 3;
        if (t(f) < t(g)) right = g;
        else left = f;
    }

    printf("%.9lf\n", left);
    return 0;
}
