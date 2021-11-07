#include <iostream>
#include <queue>

using namespace std;

int main() {
    long long n, temp;
    cin >> n;
//    priority queue because it always keeps sorted
    priority_queue<long long, vector<long long>, greater<long long> > q;

    for (long long i = 0; i < n; ++i) {
        cin >> temp;
        q.push(temp);
    }

    long long cost = 0;

    while (q.size() > 1) {
        temp = q.top();
        q.pop();
        temp += q.top();
        q.pop();
        q.push(temp);
        cost += temp;
    }

    cout << cost;
    return 0;
}
