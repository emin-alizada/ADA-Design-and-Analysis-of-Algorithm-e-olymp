#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> v) {
    for (int el: v) {
        cout << el << " ";
    }
    cout << endl;
}

int main() {
//    stl merge function
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<int> res (n+m);
    merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());

    printVector(res);

    return 0;
}
