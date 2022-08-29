#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n][n],b[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    int u=0,count=0,odd=0,flag=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]) count++;
        }
        if(count%2){
            cout<<i<<endl;
            flag=0;
        }
        count=0;
    }
    if(flag) cout<<-1;
    return 0;
}