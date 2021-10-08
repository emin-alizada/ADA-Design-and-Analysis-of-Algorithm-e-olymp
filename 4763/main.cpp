#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ver, edge;
    int start, end;
    cin >> ver >> edge;

    vector<vector<int>> v (ver, vector<int>(ver, 0));

    for (int i = 0; i < edge; ++i) {
        cin >> start >> end;
        v[start - 1][end - 1] = 1;
        v[end - 1][start - 1] = 1;
    }

    for (const auto& row: v) {
        for (int a: row) {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
