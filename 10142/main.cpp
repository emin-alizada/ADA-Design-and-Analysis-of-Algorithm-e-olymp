#include <iostream>
#include "deque"

using namespace std;

int main() {
    int n, nCopy, temp, time = 0;
    deque<int> given, ideal;

    cin >> n;

    nCopy = n;
    while (nCopy--) {
        cin >> temp;

        given.push_back(temp);
    }

    nCopy = n;
    while (nCopy--) {
        cin >> temp;

        ideal.push_back(temp);
    }

    while (!ideal.empty()) {
        if (ideal.front() == given.front()) {
            ideal.pop_front();
            given.pop_front();
            time++;
        } else {
            temp = given.front();
            given.pop_front();
            given.push_back(temp);
            time++;
        }
    }

    cout << time;

    return 0;
}
