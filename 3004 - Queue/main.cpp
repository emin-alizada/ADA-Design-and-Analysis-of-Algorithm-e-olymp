#include <iostream>
#include <queue>

using namespace std;

int main() {
//    priority queue by default has the biggest value on top, but this version has smallest value on top
    priority_queue<long long, vector<long long>, greater<> > pq;

    long long n, k, time, temp;

    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> time;

//        Serving first K customers
        if (pq.size() != k) {
            pq.push(time);
        } else {
//            Adding up the smallest value with the next clients value
            temp = pq.top();
            pq.pop();
            pq.push(time + temp);
        }
    }

//    Popping smallest values from priority queue while the last element will be our answer
    while (pq.size() > 1) {
        pq.pop();
    }

    cout << pq.top();

    return 0;
}
