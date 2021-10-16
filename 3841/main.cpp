#include <iostream>
#include <queue>

using namespace std;

bool process(priority_queue<int> &q)
{
    while (!q.empty()) {
        int desired = q.top();
        q.pop();

        priority_queue<int> temp;

        while (desired--) {
            if (q.empty()) {
                return false;
            }

            if (q.top() != 1) {
                temp.push(q.top() - 1);
            }

            q.pop();
        }

        while (!temp.empty()) {
            q.push(temp.top());
            temp.pop();
        }
    }

    return true;
}

int main() {
    priority_queue<int> pq;
    int n;
    char c;

//    reading input line by line
    while (scanf("%d%c", &n, &c) == 2)
    {
       pq.push(n);

        if (c == '\n') {
            cout<< (process(pq) ? "ok" : "fail") << endl << endl;

//            emptying pq for the next test case
            while (!pq.empty()) {
                pq.pop();
            }
        }
    }
    return 0;
}