#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, temp, temp2;
    cin >> n;

    vector<int> v(n, 0);

    while(--n) {
        cin >> temp >> temp2;
        v[temp - 1] += 1;
        v[temp2 - 1] += 1;
    }

    int max = 0;

    for(auto a: v) {
        if (a >= max) {
            max = a;
        }
    }

    cout << max+1;

    return 0;
}
