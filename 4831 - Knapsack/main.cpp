#include <iostream>
using namespace std;

int main() {
    int s, w, i;

    int m[10010];

    for (int j = 0; j < 10010; ++j) {
        m[j] = 0;
    }

    m[0] = 1;


    cin >> s;

    while(scanf("%d",&w) == 1)
    {
        for(i = s; i >= w; i--) {
//            If we can receive this number from any previous active ones
            if (m[i - w] == 1) m[i] = 1;
        }
    }

    int res = 0;
    for(i = s; ; i--) {
        if (m[i] > 0) {
            res = i;
            break;
        }
    }

    cout << res;

    return 0;
}
