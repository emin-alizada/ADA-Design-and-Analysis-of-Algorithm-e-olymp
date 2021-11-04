#include <iostream>
#include <math.h>

#define EPS 1e-12
#define PI acos(-1.0)


using namespace std;

int n;

int main() {
    cin >> n;
    int i;
    double fi;

    double left = n / 2, right = n * n, middle;

    while (right - left > EPS) {
        middle = (left + right) / 2;

        for (fi = 0, i = 1; i <= n; i++) {
            double angle = (2 * middle * middle - i * i) / (2 * middle * middle);

            if ((angle < -1.0) || (angle > 1.0)) {
                fi = 100;
                break;
            }
            fi += acos(angle);
        }

        if (fi <= 2 * PI) {
            right = middle;
        } else {
            left = middle;
        }
    }

    printf("%.8lf\n", left);

    return 0;
}
