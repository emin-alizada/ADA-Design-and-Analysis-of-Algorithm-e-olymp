#include <iostream>
#include "deque"

using namespace std;

int main() {
    int n, op, temp;
    deque<int> shelf;

    cin >> n;

    while (n--) {
        cin >> op;

        switch (op) {
            case 1: {
                cin >> temp;

                shelf.push_back(temp);

                break;
            }
            case 2: {
                cin >> temp;

                shelf.push_front(temp);

                break;
            }
            case 3: {
                cout << shelf.back() << endl;

                shelf.pop_back();

                break;
            }
            case 4: {
                cout << shelf.front() << endl;

                shelf.pop_front();

                break;
            }
        }
    }


    return 0;
}
