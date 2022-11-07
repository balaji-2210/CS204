#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vtemp(n);
    vector<vector<int>> v(n, vtemp);
    vector<int> hash(n);

    for(int x=0; x<n-1; x++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        v[a][b]++;
        v[b][a]++;
        hash[a]++;
        hash[b]++;
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(int i=0; i<n; i++){
    //     cout<<hash[i]<<" ";
    // }
    // cout<<endl<<endl;

    int count=n-2;
    while(count){
        int flag=0;
        for(int p=0; p<n; p++){
            if(hash[p]==1){
                for(int i=0; i<n; i++){
                    if(v[p][i]){
                        cout<<i+1<<" ";
                        v[p][i]--; v[i][p]--;
                        hash[p]--; hash[i]--;
                        count--;
                        flag++;
                        break;
                    }
                }
                if(flag) break;
            }
        }
    }
    return 0;
}