#include <iostream>
#include "vector"

using namespace std;

int main() {
    vector<vector<long long>> testCases;

    long long from, to;
    long long max = 10000000;

    while (cin >> from >> to) {
        testCases.push_back({from, to});
    }

    vector<int> arr(max+1, 1);

    for (int i = 2; i * i <= max; ++i) {
        if (arr[i] == 1) {
            for (int j = 2 * i; j <= max; j += i) {
                arr[j] = 0;
            }
        }
    }

    for (int i = 2; i <= max; i++) {
        arr[i] = arr[i] + arr[i - 1];
    }

    for (auto &test: testCases) {
        int count = arr[test[1]] - arr[test[0] - 1];
        cout << count << endl << endl;
        count = 0;
    }

    return 0;
}