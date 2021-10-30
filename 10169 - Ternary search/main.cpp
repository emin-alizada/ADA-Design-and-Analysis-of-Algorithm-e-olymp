#include <iostream>

using namespace std;

#define EPS 0.0000001

double a, b;

double f(double x) {
    return x * x + a * x + b;
}

double ternarySearch(double a, double b) {
    double g, h;
    while (b - a > EPS) {
        g = a + (b - a) / 3;
        h = a + 2 * (b - a) / 3;
        if (f(g) <= f(h)) {
            b = h;
        } else {
            a = g;
        }
    }
    return (a + b) / 2;
}

int main() {
    cin >> a >> b;
    cout << ternarySearch(-100, 100);
    return 0;
}
