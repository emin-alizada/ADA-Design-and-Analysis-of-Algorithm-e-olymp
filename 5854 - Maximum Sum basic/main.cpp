//
//  main.cpp
//  e-olymp Maximum Sum basic(5854)
//
//  Created by Emin Alizade on 6/24/19.
//  Copyright © 2019 Emin Alizade. All rights reserved.
//

#include <iostream>
//#include <bits/stdc++.h>  //need to write in e-olymp, no need in XCODE
using namespace std;

// Week 9: November 17 - Dynamic Programming
int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>a[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(i==0){
                continue;
            }
            else if(j==0){
                a[i][j]+=max(a[i-1][j],a[i-1][j+1]);
            }
            else if(j==m-1){
                a[i][j]+=max(a[i-1][j],a[i-1][j-1]);
            }
            else{
                a[i][j]+=max(max(a[i-1][j],a[i-1][j-1]),a[i-1][j+1]);
            }
        }
    }
    long long max=LONG_MIN;

    for (int j=0; j<m; j++) {
        if(a[n-1][j]>=max){
            max=a[n-1][j];
        }
    }

    cout<<max;
    return 0;
}