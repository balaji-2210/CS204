#include<iostream>
#include<vector>
using namespace std;

int main(){
	cout<<"Enter number of vertices & number of edges: ";
    int n,m;
    cin>>n>>m;
    int v[n][n];
    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		v[i][j]=0;
    	}
    }
	cout<<"Enter "<<m<<" edges: \n";
    for(int i=0; i<m; i++){
        int p,q;
        cin>>p>>q;
        v[p-1][q-1]=1; v[q-1][p-1]=1;
    }
    int visited[n];
    for(int i=0; i<n; i++) visited[i]=0;
    vector<int> a,b;
    bool good=true;
    for(int i=0; i<n; i++){
    	bool inA=false, inB=false;
        if(visited[i]==0){
        	for(int x=0; x<a.size(); x++){
        		if(v[i][a[x]]==1) inA=true;
        	}
        	if(!inA){
        		a.push_back(i);
        		visited[i]=1;
        		continue;
        	}
        	for(int y=0; y<b.size(); y++){
        		if(v[i][b[y]]==1) inB=true;
        	}
        	if(!inB){
        		b.push_back(i);
        		visited[i]=1;
        		continue;
        	}
        	if(inA && inB) good=false;
        	}
    }
    if(good) cout<<"Good\n";
    else cout<<"Bad\n";
    return 0;
}
