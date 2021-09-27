#include <iostream>
#include "map"
#include "stack"
#include "vector"

using namespace std;

int main() {
    map<int, int> freq;

    vector<stack<int>> st;

    string str;
    int temp;

    while (cin >> str) {
        if (str == "push") {
            cin >> temp;

//            cout << st.size() << " while try to access" << freq[temp] << endl;

            if (st.size() < freq[temp] + 1) {
                stack<int> tempStack;

                st.push_back(tempStack);
            }

            st[freq[temp]].push(temp);

            freq[temp]++;
        } else if (str == "pop") {
            int mostFreq = st[st.size() - 1].top();

            cout << mostFreq << endl;
            st[st.size() - 1].pop();

            if (st[st.size() - 1].empty()) {
                st.erase(st.end() - 1);
            }

            freq[mostFreq]--;
        }
    }

    return 0;
}
