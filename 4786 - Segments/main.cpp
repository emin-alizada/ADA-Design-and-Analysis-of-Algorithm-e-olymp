#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class segment
{
public:
    int start, fin;
    segment(int start, int fin) : start(start), fin(fin) {}
};

vector<segment> v;

int f(segment a, segment b)
{
    return a.fin <= b.fin;
}


int main() {
    int n, s, e;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> s >> e;
        v.push_back(segment(s, e));
    }

    sort(v.begin(), v.end(), f);

    int cur = 0, res = 1;

    for (int i = 1; i < v.size(); ++i) {
        if (v[i].start >= v[cur].fin) {
            cur = i;
            res++;
        }
    }

    cout << res;

    return 0;
}
