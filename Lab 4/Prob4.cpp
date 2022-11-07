#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    char t;
    int count=0,add=0,flag=0;
    for(int i=0; i<n; i++){
        while(true){
            cin>>t;
            if(t=='#') break;
            count++;
        }
        if(count%2){
            if(count==n-1){
                flag=1;
                break;
            }
            else add++;
        }
        count=0;
    }
    if((add%2)||flag) cout<<-1;
    else cout<<add/2;
    return 0;
}