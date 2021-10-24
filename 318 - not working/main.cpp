#include <iostream>
#include <map>

using namespace std;

// 80% passes

map<string, unsigned long long> c;

unsigned long long binomCoef(unsigned long long n, unsigned long long k) {
    if (n == k) return 1;
    if (k == 0) return 1;

    string leftStr = to_string(n - 1) + "," + to_string(k - 1);
    string rightStr = to_string(n - 1) + "," + to_string(k);
    unsigned long long left = 0, right = 0;

    if (c.find(leftStr) != c.end()) {
        left = c.at(leftStr);
//        cout << "in if" << endl;
//        cout << "in if" << c.at(to_string(n) + "," + to_string(k)) << endl;
    } else {
        left = binomCoef(n - 1, k - 1);
        c.insert(make_pair(leftStr, left));
    }

    if (c.find(rightStr) != c.end()) {
        right = c.at(rightStr);
//        cout << "in if" << c.at(to_string(n) + "," + to_string(k)) << endl;
    } else {
        right = binomCoef(n - 1, k);
        c.insert(make_pair(rightStr, right));
    }

    return left + right;
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        unsigned long long n, k;

        cin >> n >> k;

        cout << binomCoef(n, k) << endl;
    }

    return 0;
}
