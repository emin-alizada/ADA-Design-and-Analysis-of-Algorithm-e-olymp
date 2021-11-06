#include <iostream>
#include <math.h>

using namespace std;

double x, y, c;

int main() {
    double left, right, a, b, c1, d;

    while (cin >> x >> y >> c) {
        left = 0;
        right = x > y ? y : x; // min of x,y

        d = (left + right) / 2; // AC the value that we look for

        do {
            a = sqrt(x*x - d*d); // from triangle ABC
            b = sqrt(y*y - d*d); // from triangle ACD

            c1 = (a*b) / (a+b);

            if (c1 < c) {
                right = (left + right) / 2;
            } else {
                left = (left + right) / 2;
            }

            d = (left + right) / 2;

        } while (fabs(c1 - c) > 0.00001);

        printf("%.3lf\n",d);
    }

    return 0;
}
