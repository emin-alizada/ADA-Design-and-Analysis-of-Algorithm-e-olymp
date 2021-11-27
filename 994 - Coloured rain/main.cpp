#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int hills[n+1];
    int roads[n+1][n+1];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> roads[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        cin >> hills[i];
    }

    int badBridge = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (roads[i][j] && hills[i] != hills[j]){
                badBridge++;
            }
        }
    }

    cout << badBridge;

    return 0;
}
