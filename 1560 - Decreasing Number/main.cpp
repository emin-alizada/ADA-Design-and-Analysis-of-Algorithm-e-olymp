//
//  main.cpp
//  e-olymp Decreasing Number(1560)
//
//  Created by Emin Alizade on 6/23/19.
//  Copyright © 2019 Emin Alizade. All rights reserved.
//

#include <iostream>
using namespace std;

// Week 9 Noveember 17 Dynamic programming

int main() {
    long long d[1000001];
    int n;
    d[1]=0;
    for(int i=2;i<=1000000;i++){
        d[i]=d[i-1]+1;
        if(i%2==0) d[i]=min(d[i],d[i/2]+1);
        if(i%3==0) d[i]=min(d[i],d[i/3]+1);
    }
    while(cin>>n){
        cout<<d[n]<<endl;
    }
    return 0;
}