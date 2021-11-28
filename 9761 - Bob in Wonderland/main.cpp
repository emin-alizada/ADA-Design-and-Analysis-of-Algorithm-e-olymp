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

    int sum = 0;

//    Number of operations is equal to the sum of graph vertices that have degree more than two
//    Because for the problem solution we need to have vertices with degree = 2, only two vertices can have degree 1
    for(auto a: v) {
        if (a > 2) {
            sum += a-2;
        }
    }

    cout << sum;

    return 0;
}
