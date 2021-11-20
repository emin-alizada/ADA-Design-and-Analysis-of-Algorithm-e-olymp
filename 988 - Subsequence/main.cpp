#include <iostream>
#define MAX 1001

int x[MAX], lis[MAX];

using namespace std;

//Week 9: November 19 - Longest Increasing Subsequence (LIS)
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    int len, i;
    for (len = i = 0; i < n; i++) {
        int pos = lower_bound(lis,lis+len,x[i]) - lis;

//        prints for understanding of algo
//        cout << "x " << x[i] << endl;
//        cout << "pos " << pos << endl;
//        cout << "len " << len << endl;

        if (pos < len) {
            lis[pos] = x[i];
        } else {
            lis[len++] = x[i];
        }

//        cout << "list is ";
//        for (int j = 0; j < len; ++j) {
//            cout << lis[j] << " ";
//        }
//        cout << endl;
    }

    cout << len;

    return 0;
}
