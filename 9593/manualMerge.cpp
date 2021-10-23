//
// Created by Emin Alizade on 23.10.21.
//

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

void mergeVectors(vector<int> f,  int fLength, vector<int> s,  int sLength, vector<int> &res) {
//    f - first, s - second
    res.resize(fLength + sLength);

    int fp = 0; // first pointer
    int sp = 0; // second pointer

    int i;

    for (i = 0; fp < fLength && sp < sLength; i++) {
        if (f[fp] < s[sp]) {
            res[i] = f[fp];
            fp++;
        } else {
            res[i] = s[sp];
            sp++;
        }
    }

    while (fp < fLength) {
        res[i] = f[fp];
        fp++;
        i++;
    }

    while (sp < sLength) {
        res[i] = s[sp];
        sp++;
        i++;
    }
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
    mergeVectors(a, n, b, m, res);

    printVector(res);

    return 0;
}
