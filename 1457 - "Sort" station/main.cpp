#include <iostream>

using namespace std;

int main() {
    int n, maxM;
    cin >> n >> maxM;

    int m[n], max[n];
//    We  have two arrays one for elements, second for max elemet up to this point
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        if (i == 0) {
            max[i] = m[i];
        } else {
            if (max[i-1] > m[i]) {
                max[i] = max[i-1];
            } else {
                max[i] = m[i];
            }
        }
    }

//    We compare from end to the beginning each element is compared with max that was up to thiis point
    bool res = true;
    for (int i = n-1; i > 0 ; --i) {
        if (m[i] < max[i] && (m[i] + max[i] > maxM)) {
            res = false;
        }
    }

    cout << (res ? "Yes" : "No");
    return 0;
}