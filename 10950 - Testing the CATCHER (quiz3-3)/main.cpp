#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Testing the CATCHER - 10950

int main() {
    int temp, testNumber = 0;
    vector<int> arr;

    while (cin >> temp) {
        arr.resize(0);
        if (temp == -1) {
            break;
        }
        arr.push_back(temp);

        while (cin >> temp) {
            if (temp == -1) {
                break;
            }

            arr.push_back(temp);
        }


        reverse(arr.begin(), arr.end());
        int len, i;
        vector<int> lis(arr.size(), 0);
        for (len = i = 0; i < arr.size(); i++) {
            int pos = lower_bound(lis.begin(),lis.begin() + len ,arr[i]) - lis.begin();

//        prints for understanding of algo
//        cout << "x " << arr[i] << endl;
//        cout << "pos " << pos << endl;
//        cout << "len " << len << endl;

            if (pos < len) {
                lis[pos] = arr[i];
            } else {
                lis[len++] = arr[i];
            }

//        cout << "list is ";
//        for (int j = 0; j < len; ++j) {
//            cout << lis[j] << " ";
//        }
//        cout << endl;
        }


        if(testNumber) {
            puts("");
        }
        printf("Test #%d:\n", ++testNumber);
        printf("  maximum possible interceptions: %d\n", len);

//        for (int i = 0; i < arr.size(); ++i) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
    }

    return 0;
}

/*


 */