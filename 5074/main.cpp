//
//  main.cpp
//  e-olymp Degrees of vertices by a list of edges(5074)
//
//  Created by Emin Alizade on 6/24/19.
//  Copyright © 2019 Emin Alizade. All rights reserved.
//

#include <iostream>
using namespace std;
int a[101];

int main(int argc, const char * argv[]) {
    int n,m;
    int x,y;
    cin>>n>>m;
    for(int i=0;i<m;i++){

        cin>>x>>y;
        a[x-1]++; a[y-1]++;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }

    return 0;
}