#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long m;

map<string , long long> p;

vector<long long > dsu;
vector<long long > depthDsu;
vector<long long > num;

string s1, s2;
long long counter = 1;

long long repr(long long i) {
//    Path compression heuristic
    if (i == dsu[i]) {
        return i;
    }
    return dsu[i] = repr(dsu[i]);
}

void make_union(long long a, long long b) {
    a = repr(a);
    b = repr(b);

    if (a == b) {
        return;
    } else {
        if (depthDsu[a] > depthDsu[b]) {
            swap(a, b);
        }
        dsu[a] = b;
        if (depthDsu[a] == depthDsu[b]) {
            depthDsu[b]++;
        }
        num[b] += num[a];
    }
}

void setCreate(long long i) {
    dsu.push_back(i);
    depthDsu.push_back(0);
    num.push_back(1);
}

int main() {
    long long n;

    cin >> n;

    while (n--) {
        cin >> m;

        p.clear();

        dsu = vector<long long>(1, 0);
        depthDsu = vector<long long>(1, 0);
        num = vector<long long>(1, 0);

        counter = 1;

        for (long long i = 0; i < m; ++i) {
            cin >> s1 >> s2;

            if (p[s1] == 0) {
                p[s1] = counter;
                setCreate(counter);
                counter++;
            }

            if (p[s2] == 0) {
                p[s2] = counter;
                setCreate(counter);
                counter++;
            }

            long long from = p[s1];
            long long to = p[s2];

            make_union(from, to);
            make_union(to, from);

            long long r1 = repr(from);
            long long r2 = repr(to);
            cout << max(num[r1], num[r2]) << endl;
        }
    }

    return 0;
}

/*
2
3
Fred Barney
Barney Betty
Betty Wilma
2
Fred Barney
Barney Betty

 */