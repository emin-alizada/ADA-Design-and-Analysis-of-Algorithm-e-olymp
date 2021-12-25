#include <iostream>
#include <algorithm>

using namespace std;

int a[5];

// TODO review the code


bool RunSum(int Sum, int index) {
    if (index == 5) {
        if (Sum == 23) {
            return true;
        } else {
            return false;
        }
    }

    if (RunSum(Sum + a[index], index + 1)) {
        return true;
    }

    if (RunSum(Sum - a[index], index + 1)) {
        return true;
    }

    if (RunSum(Sum * a[index], index + 1)) {
        return true;
    }
    return false;
}

int main() {

    while (true) {
        for (int i = 0; i < 5; ++i) {
            cin >> a[i];
        }

        bool allZeroes = true;

        for (int i = 0; i < 5; ++i) {
            if (a[i] != 0) {
                allZeroes = false;
            }
        }

        if (allZeroes) {
            break;
        }

        bool flag;
        sort(a,a+5);

        do {
            flag = RunSum(a[0],1);

            if (flag) {
                break;
            }
        } while(next_permutation(a,a+5));

        if (flag) {
            printf("Possible\n");
        }
        else {
            printf("Impossible\n");
        }

        memset(a,0,sizeof(a));
    }
    return 0;
}
