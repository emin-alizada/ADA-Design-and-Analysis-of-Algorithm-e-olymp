//
//  main.cpp
//  e-olymp Cash Machine(138)
//
//  Created by Emin Alizade on 5/10/19.
//  Copyright © 2019 Emin Alizade. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,count=0;
    cin>>n;
    if(n/500>0){
        count+=n/500;
        n=n%500;
    }
    if(n/200>0){
        count+=n/200;
        n=n%200;
    }
    if(n/100>0){
        count+=n/100;
        n=n%100;
    }
    if(n/50>0){
        count+=n/50;
        n=n%50;
    }
    if(n/20>0){
        count+=n/20;
        n=n%20;
    }
    if(n/10>0){
        count+=n/10;
        n=n%10;
    }
    if(n==0){
        cout<<count;
    }
    else cout<<"-1";
    return 0;
}