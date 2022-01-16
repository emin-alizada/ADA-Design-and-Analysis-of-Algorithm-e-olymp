#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector <int> a;
    int n, temp, tip = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (a[i] - i > 0) {
            tip += a[i] - i;
        } else {
            break;
        }
    }

    cout << tip << endl;
}