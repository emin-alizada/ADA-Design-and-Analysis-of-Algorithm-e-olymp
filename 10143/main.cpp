#include <iostream>
#include "deque"
#include "vector"

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        if (n == 0) {
            break;
        }

        deque<int> cards;
        vector<int> discarded;

        for (int i = 1; i <= n; ++i) {
            cards.push_front(i);
        }

        while (cards.size() > 1) {
            discarded.push_back(cards.back());

            cards.pop_back();

            int temp = cards.back();

            cards.pop_back();

            cards.push_front(temp);
        }

        cout << "Discarded cards: ";

        for (int i = 0; i < discarded.size(); i++) {
            cout << discarded[i];

            if (i < discarded.size() - 1) {
                cout <<  ", " ;
            }
        }

        cout << endl;

        cout<< "Remaining card: " << cards.front() << endl;
    }

    return 0;
}
