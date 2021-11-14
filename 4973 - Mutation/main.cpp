#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class segment
{
public:
    int start, fin;
    segment(int start, int fin) : start(start), fin(fin) {}
};


int f(segment a, segment b)
{
    return a.fin <= b.fin;
}

// Week 7 - greedy (activity selection problem)
int main() {
    int n;
    cin >> n;

    int a[n];
    vector<segment> temp(n + 1, segment(-1, -1)), filteredSegments;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (temp[a[i]].start == -1) {
            temp[a[i]].start = i;
            temp[a[i]].fin = i;
        } else {
            temp[a[i]].fin = i;
        }
    }

//    Filtering out empty segments
    for(segment s: temp) {
        if (s.start != -1) {
            filteredSegments.push_back(s);
        }
    }

    sort(filteredSegments.begin(), filteredSegments.end(), f);

    int cur = 0, res = 1;

    for (int i = 1; i < filteredSegments.size(); ++i) {
        if (filteredSegments[i].start >= filteredSegments[cur].fin) {
            cur = i;
            res++;
        }
    }

    cout << filteredSegments.size() - res;

    return 0;
}
