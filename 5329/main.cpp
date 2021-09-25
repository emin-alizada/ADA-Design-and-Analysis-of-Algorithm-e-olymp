#include <iostream>

using namespace std;

int main() {
    int numberOfStudents, numberOfGettingYogurt;
    int mod = 9929;

    cin >> numberOfStudents >> numberOfGettingYogurt;

    int C[501][501];

//    Here we calculate all cases beforehand
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) {
//            Base cases
            if (j == 0 || j == i) {
                C[i][j] = 1;
            }
            else {
//                There is a formula to calculate binominal coefficent
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
            }
        }
    }


    cout << C[numberOfStudents][numberOfGettingYogurt];

    return 0;
}