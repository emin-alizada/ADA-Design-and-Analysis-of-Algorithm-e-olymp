#include <iostream>
#include <vector>

#define MAX 5001
#define INF 0x3F3F3F3F
using namespace std;

string str[MAX];
int used[MAX], dist[MAX], distTo[MAX];
int n, k;
vector<string> edges;

int strDifference(string a, string b) {
    int diff = 0;

    for (int i = 0; i < k; ++i) {
        if (a[i] != b[i]) {
            diff++;
        }
    }

    return diff;
}

double Prim() {
    memset(dist, 0x3F, sizeof(dist));
    memset(distTo, -1, sizeof(dist));
    memset(used, 0, sizeof(used));

    double res = 0;
    int cur = 0;
    dist[cur] = 0;
    used[cur] = 1;
    for (int i = 1; i < n; i++) {


//        Relaxation process
        for (int j = 0; j < n; j++) {
            if (!used[j] && (strDifference(str[cur], str[j]) < dist[j])) {
                dist[j] = strDifference(str[cur], str[j]);
//                Dist to is like in presentation when we relax we keep that is distance to which vertex
                distTo[j] = cur;
            }
        }

        int oldCur = cur;
//        choosing vertex with minimum distance from current
        int min = INF;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (dist[j] < min)) {
                min = dist[j];
                cur = j;
            }
        }

        edges.push_back(to_string(cur) + " " + to_string(distTo[cur]));

        used[cur] = 1;
        res += dist[cur];
    }

    return res;
}

//Week 8 - November 12 (prim algorithm)
int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    double res = Prim();

    cout << res << endl;
    for(string s: edges) {
        cout << s << endl;
    }
    return 0;
}