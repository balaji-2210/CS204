#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n][n],b[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j]=0;
        }
    }

    char t;
    for(int i=0; i<n; i++){
        while(true){
            cin>>t;
            if(t=='#') break;
            int p = t-'0';
            a[i][p]+=1;
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