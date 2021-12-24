#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;

    int s[n], e[n];

    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> e[i];
    }

    int maxCover = INT32_MIN;

    vector<int> cover(1001,0);
    for (int i = 0; i < n; ++i) {
        for (int j = s[i]; j < e[i]; ++j) {
            cover[j]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = s[i]; j < e[i]; ++j) {
            cover[j]--;
        }

        int currentCover = 0;
        for (int j = 0; j < cover.size(); ++j) {
            if (cover[j] > 0) {
                currentCover++;
            }
        }
        maxCover = max(maxCover, currentCover);

        for (int j = s[i]; j < e[i]; ++j) {
            cover[j]++;
        }
    }

    cout << maxCover;

    return 0;
}
