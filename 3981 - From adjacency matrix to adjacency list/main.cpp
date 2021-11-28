#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, temp;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> temp;

            if (temp == 1) {
//                For each point from matrix that is one we push to vector as connection from i to j
                v[i].push_back(j);
            }
        }
    }

    for (auto vertice: v) {
        cout << vertice.size() << " ";

        for (int edge: vertice) {
            cout << edge + 1 << " ";
        }

        cout << endl;
    }

    return 0;
}
