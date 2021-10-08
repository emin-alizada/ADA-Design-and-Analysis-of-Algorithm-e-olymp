#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n][n];

    int count = 0;

    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>a[i][j];

            if(a[i][j] == 1)
                count++;
        }
    }

    cout<<count/2;
    return 0;
}
