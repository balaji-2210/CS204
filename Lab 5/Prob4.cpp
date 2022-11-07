#include <bits/stdc++.h>
using namespace std;

int num(int a[], int r){
    double num=0;
    while(r--){
        num += a[r]*pow(10.00,r);
    }
    return num;
}

int main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=n-1; i>=0; i--) cin>>a[i];
    for(int i=m-1; i>=0; i--) cin>>b[i];
    int p = num(a,n);
    int q = num(b,m);
    cout<<p-q;
    
    return 0;
}