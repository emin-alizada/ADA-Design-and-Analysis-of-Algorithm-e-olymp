#include <iostream>
#include "vector"
#include "deque"

using namespace std;

int main() {
    vector<deque < int>> vs(150001);
    int n, tempA, tempB;
    string str;

    cin >> n;

    while (n--) {
        cin >> str;

        if (str == "pushfront") {
            cin >> tempA >> tempB;

            vs[tempA].push_front(tempB);
        } else if (str == "pushback") {
            cin >> tempA >> tempB;

            vs[tempA].push_back(tempB);
        } else if (str == "popfront") {
            cin >> tempA;

            cout <<  vs[tempA].front() << endl ;

            vs[tempA].pop_front();
        } else if (str == "popback") {
            cin >> tempA;

            cout <<  vs[tempA].back() << endl ;

            vs[tempA].pop_back();
        }
    }


    return 0;
}
