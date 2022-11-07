#include <bits/stdc++.h>
using namespace std;

int num(int r){
    int num=0;
    for(int i=0; i<r; i++){
        int t;
        cin>>t;
        num += t*pow(10,r-1);
    }
    return num;

}

int main(){
    int n,m;
    cin>>n>>m;
    int p = num(n);
    int q = num(m);
    cout<<p*q;
    
    return 0;
}