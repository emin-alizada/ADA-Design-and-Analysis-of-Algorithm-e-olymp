#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector<vector<char>> grid; // declare the grid - two-dimensional char array

// start depth first search at position (x, y)
void dfs(int i, int j) {
    // if we out of bounds of the grid - return
    if ((i < 0) || (i >= n) || (j < 0) || (j >= n)) {
        return;
    }

    // if we come to empty cell - return
    if (grid[i][j] == '.') {
        return;
    }

    // mark current position as used (passed)
    grid[i][j] = '.';

    // run depth first search in four neighbouring directions
    dfs(i - 1, j - 1);
    dfs(i - 1, j);
    dfs(i - 1, j + 1);
    dfs(i, j - 1);
    dfs(i, j + 1);
    dfs(i + 1, j - 1);
    dfs(i + 1, j);
    dfs(i + 1, j + 1);
}

int main() {
    grid = vector<vector<char>>(101, vector<char>(101, '.'));

    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        grid[x][y] = '*';
    }

    // count the number of asteroids - number of connected components
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') // if position (i, j) contains a stone, run dfs from it
            {
                dfs(i, j);
                count++; // increase the number of connected components
            }
        }
    }

    // print the answer
    cout << count << endl;
    return 0;
}