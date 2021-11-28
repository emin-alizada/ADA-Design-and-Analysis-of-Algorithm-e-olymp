#include <iostream>
#include <map>

using namespace std;

map<string , int> values;

// Solution here is to cache values that we have found and simplify the right part function

int funFuction(int x, int y) {
    if (x<=0 || y<=0) {
        return 0;
    } else if (x <= y) {
        int leftPart, rightPart;
        string left = to_string(x-1) + "," + to_string(y-2);
        string right = to_string(x-2) + "," + to_string(y-1);

        if (values.find(left) == values.end()) {
            leftPart = funFuction(x - 1, y - 2);

            values.insert(pair<string , int>(left, leftPart));
        } else {
            leftPart = values.find(left)->second;
        }

        if (values.find(right) == values.end()) {
            rightPart = funFuction(x-2, y-1);
            values.insert(pair<string , int>(right, rightPart));
        } else {
            rightPart = values.find(right)->second;
        }

        return leftPart + rightPart  + 2;
    } else {
//        x>y contidion;

//          if x > y and function is there to return  f(x-2, y-2) it will always stay x>y so we can simplify
        if (y % 2 == 0) {
            return y/2;
        } else {
            return y/2 + 1;
        }
    }
}

int main() {
    int x,y;

    cin >> x >> y;

    cout << funFuction(x, y);

    return 0;
}
