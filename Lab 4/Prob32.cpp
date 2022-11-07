#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    int t,count=0,add=0,odd=0;
    int flag=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            t=a[i][j];
            if(t) count++;
        }
        if(count%2){
            odd++;
        }
        count=0;
    }
    if((odd%2)||flag) cout<<-1;
    else cout<<odd/2;
    return 0;
}