#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1010

using namespace std;

int a[MAX][MAX], dp[MAX][MAX];
int i,j, n ,m;

vector<pair<int, int>> path;

// TODO redo it after exam
int main() {
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);

    dp[1][1] = a[1][1];
    for (i = 2; i <= n; i++)
        dp[i][1] = dp[i - 1][1] + a[i][1];
    for (j = 2; j <= m; j++)
        dp[1][j] = dp[1][j - 1] + a[1][j];

    for (i = 2; i <= n; i++)
        for (j = 2; j <= m; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];

    printf("%d\n", dp[n][m]);

    i = n; j = m;

    while (i > 1 && j > 1)
    {
        path.push_back(make_pair(i, j));
        if (dp[i - 1][j] + a[i][j] == dp[i][j]) i--; else j--;
    }

    while (i > 1) path.push_back(make_pair(i, j)), i--;
    while (j > 1) path.push_back(make_pair(i, j)), j--; path.push_back(make_pair(1, 1));

    reverse(path.begin(), path.end());

    for (i = 0; i < path.size(); i++)
        printf("%d %d\n", path[i].first, path[i].second);

    return 0;
}

// My version not working

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//    int n, m;
//    vector<pair<int, int>> path;
//
//    cin >> n >> m;
//
//
//    int dp[n+1][m+1];
//
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            cin >> dp[i][j];
//        }
//    }
//
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            if (i == 1 && j == 1) {
//                continue;
//            }
//
//            if (i == 1) {
//                dp[i][j] += dp[i][j-1];
//                continue;
//            }
//
//            if (j == 1) {
//                dp[i][j] += dp[i-1][j];
//                continue;
//            }
//
//            dp[i][j] += min(dp[i][j-1], dp[i-1][j]);
//        }
//    }
//
//    cout << dp[n][m] << endl;
//
//    int i = n, j = m;
//
//    while (i >= 1 && j >= 1) {
//        path.push_back(make_pair(i, j));
//
//        if (i == 1) {
//            j--;
//        } else if (j == 1) {
//            i--;
//        } else if (dp[i-1][j] < dp[i][j-1]) {
//            i--;
//        } else {
//            j--;
//        }
//    }
//
//    return 0;
//}