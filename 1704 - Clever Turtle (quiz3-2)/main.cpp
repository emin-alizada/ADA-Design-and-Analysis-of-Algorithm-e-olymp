#include <iostream>
using namespace std;

// Clever Turtle 1704
int main() {
    int n,m;
    cin>>n>>m;
    long long dp[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0){
                dp[i][j]=1;
            }

            else{
                dp[i][j]= dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    cout << dp[n - 1][m - 1];
    return 0;
}