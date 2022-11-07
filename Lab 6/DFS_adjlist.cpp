#include <bits/stdc++.h>
using namespace std;

vector<int> visited;
vector<vector<int>> v;

void DepthFirstSearch(int n){
    cout<<n<<" ";
    visited[n]=1;
    for(int i=0; i<v.size(); i++){
        if(v[n][i] && !visited[i]){
            DepthFirstSearch(i);
        }
    }
}

int main(){
    int num;
    cin>>num;
    for(int i=0; i<num; i++){
        visited.push_back(0);
    }
    for(int i=0; i<num; i++){
        vector<int> temp(num);
        v.push_back(temp);
    }
    char t;
    for(int i=0; i<num; i++){
        while(true){
            cin>>t;
            if(t=='#') break;
            int p = t-'0';
            v[i][p]+=1;
        }
    }

    for(int i=0; i<num; i++){
        if(!visited[i]) DepthFirstSearch(i);
    }
    return 0;
}