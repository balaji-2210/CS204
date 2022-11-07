#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    char t;
    int count=0,flag=1;
    for(int i=0; i<n; i++){
        while(true){
            cin>>t;
            if(t=='#'){
                if(count%2){
                    flag--;
                    count=0;
                }
                break;
            }
            count++;
        }
        if(flag==0) break;
    }
    if(flag) cout<<"true";
    else cout<<"false";
    return 0;
}