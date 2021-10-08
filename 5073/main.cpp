//
//  main.cpp
//  e-olymp Multiedges (5073)
//
//  Created by Emin Alizade on 6/24/19.
//  Copyright © 2019 Emin Alizade. All rights reserved.
//



#include <iostream>
using namespace std;

int a[101][101];
int main(int argc, const char * argv[]) {
    int n,m,x,y;

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        a[x][y]++;
        if(a[x][y]>1){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}