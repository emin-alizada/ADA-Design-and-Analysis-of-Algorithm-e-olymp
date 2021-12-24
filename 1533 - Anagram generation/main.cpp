#include <iostream>
#include <algorithm>

using namespace std;

int lt(char a, char b) {
    if (toupper(a) != toupper(b)) {
        return (toupper(a) < toupper(b));
    }

    return (a < b);
}

int main() {
    int n;

    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end(), lt);

        do {
            cout << s << endl;
        } while(next_permutation(s.begin(), s.end(), lt));
    }
    return 0;
}
