//
// Created by Emin Alizade on 09.10.21.
//

#include "iostream"

using namespace std;

int main() {
    int n, a, b, c, x;
    long long res = 0;

    cin >> n >> a >> b >> c >> x;

    int values[n], valuesStart = 0, valuesEnd = 0;
    int min[n], minStart = 0, minEnd = 0;

    fill_n(values, n, -1);
    fill_n(min, n, -1);

    for (int i = 0; i < n; ++i) {
        x = (1L * a * x * x + 1L * b * x + c) / 100 % 1000000L;

        if (x % 5 < 2) {
//            Pop value from arrays if there is an element in it
            if (valuesStart != valuesEnd) {
                if (values[valuesStart] == min[minStart]) {
//                If the value that we pop is in min array pop it from there too
                    minStart++;
                }
//            In any way we pop value from values array
                valuesStart++;
            }
        } else {
//            Push to the arrays
            values[valuesEnd++] = x;
            while (minStart != minEnd && ( x < min[minEnd - 1] ) ) {
                minEnd--;
            }
            min[minEnd++] = x;
        }

//        get Minimum and add to res
        res += minStart != minEnd ? min[minStart] : 0;
    }

    cout << res;

    return 0;
}