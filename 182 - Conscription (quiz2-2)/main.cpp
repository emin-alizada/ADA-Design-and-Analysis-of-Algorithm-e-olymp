#include <iostream>
#include <vector>
#include <algorithm>

// 182 - Conscription

using namespace std;

struct soldier
{
    long long g, h, used;
    soldier(long long g, long long h, long long used) : g(g), h(h), used(used) {}
};


int comp(soldier a, soldier b) {
    return (a.g - a.h) > (b.g - b.h);
}

int main() {
    int n,g,h, tempG, tempH;

    cin >> n >> g >> h;

    vector<soldier> s;

    for (int i = 0; i < n; ++i) {
        cin >> tempG >> tempH;
        s.push_back(soldier(tempG, tempH, 0));
    }

    if (g + h > n) {
        cout << -1;
        return 0;
    }

    sort(s.begin(), s.end(), comp);

    long long pow = 0;

    for (int i = 0; i < n; ++i) {
        if (g > 0) {
            if (s[i].used ==0) {
                pow += s[i].g;
                s[i].used = 1;
                g--;
            }
        }
    }

    for (int i = n-1; i >= 0 ; i--) {
        if (h > 0) {
            if (s[i].used == 0) {
                pow += s[i].h;
                s[i].used = 1;
                h--;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (s[i].used == 0) {
            if (s[i].g > s[i].h) {
                pow += s[i].g;
            } else {
                pow += s[i].h;
            }
        }
    }

    cout << pow;

    return 0;
}
