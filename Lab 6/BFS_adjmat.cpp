#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> visited;
vector<vector<int>> v;

void BreadthFirstSearch(int n){
    cout<<n<<" ";
    visited[n]=1;
    q.push(n);
    while(!q.empty()){
        int m = q.front();
        q.pop();
        for (int i=0; i<v.size(); i++){
            if(v[m][i] && !visited[i]){
                cout<<i<<" ";
                visited[i]=1;
                q.push(i);
            }
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
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            int t;
            cin>>t;
            v[i][j]=t;
        }
    }

    for(int i=0; i<num; i++){
        if(!visited[i]) BreadthFirstSearch(i);
    }
    return 0;
}