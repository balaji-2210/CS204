#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<int> visited;
bool connected;

void DFS(int n, int m){
    visited[n]=1;
    for(int i=0; i<v.size(); i++){
        if(v[n][i] && !visited[i]){
            if(i==m){
                connected = true;
                return;
            }
            DFS(i,m);
        }
    }
}

bool isLoop(int a, int b){
    int n = v.size();
    visited.clear();
    for(int i=0; i<n; i++){
        visited.push_back(0);
    }
    connected = false;
    DFS(a,b);
    return connected;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        vector<int> temp(n);
        v.push_back(temp);
    }

    int count=n;
    while(true){
        int a,b;
        cin>>a>>b;
        if(a==0) break;
        a--;b--;
        count--;
        if(isLoop(a,b)) count++;
        cout<<count<<endl;
        v[a][b]++; v[b][a]++;
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
    // cout<<endl;
    return 0;
}