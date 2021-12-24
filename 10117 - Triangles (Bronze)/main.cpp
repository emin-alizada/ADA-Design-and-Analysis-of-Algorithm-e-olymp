#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin>>n;

    int x[n], y[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    int maxArea = INT32_MIN;

//    Triangle is rectangular
//    Imagine 3 points that are vertices of triangle: i,j,k
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (y[i] == y[j] && x[j] == x[k]) {
                    int area = abs((x[j] - x[i]) * (y[k] - y[j]));

                    if (area > maxArea) {
                        maxArea = area;
                    }
                }
            }
        }
    }

    cout << maxArea;

    return 0;
}
