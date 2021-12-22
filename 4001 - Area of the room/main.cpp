#include <iostream>
#include <string>

using namespace std;

int n;
string m[11]; // declare the grid - two-dimensional char array
int area = 0;

// start depth first search at position (x, y)
void dfs(int i, int j) {
    // if we out of bounds of the grid - return
    if ((i < 0) || (i >= n) || (j < 0) || (j >= n)) {
        return;
    }

    if (m[i][j] == '*') {
        return;
    }

    // mark current position as used (passed)
    m[i][j] = '*';
    area++;

    // run depth first search in four neighbouring directions
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    int x, y;
    cin >> x >> y;

    dfs(x - 1, y - 1);



    // print the answer
    cout << area << endl;
    return 0;
}