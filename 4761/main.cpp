#include <iostream>

using namespace std;

int main() {
    int n, temp;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> temp;
//            Loop can only occur in central diagonal
            if (i == j && temp == 1) {
                cout << "YES";
                return 0;
            }
        }
    }
    
    cout << "NO";
    
    return 0;
}
