#include <iostream>
#include <queue>

using namespace std;

// 8598 - Wizard and wolves

int main() {
    long long n, a, b, temp;

    cin >> n >> a >>b;

    priority_queue<long long> pq;

    for (long long i = 0; i < n; ++i) {
        cin >> temp;
        pq.push(temp);
    }

    long long count = 0;

    while (!pq.empty()) {
        priority_queue<long long> tpq; //temp pq


        count++;
        long long currentSizeOfPq = pq.size();
        for (long long i = 0; i < currentSizeOfPq; ++i) {
            if(i == 0) {
                temp = pq.top();
                pq.pop();
                temp -= a;

                if (temp > 0) {
                    tpq.push(temp);
                }
            } else {
                temp = pq.top();
                pq.pop();
                temp -= b;

                if (temp > 0) {
                    tpq.push(temp);
                }
            }
        }

        pq = tpq;
    }

    cout << count;


    return 0;
}