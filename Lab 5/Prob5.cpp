#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int total=n+m;
    int a[n],b[m],pmat[m][total],pdt[total];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    for(int i=0; i<m; i++){
        for(int j=0; j<total; j++){
            pmat[i][j]=0;
        }
    }
    for(int i=0; i<total; i++) pdt[i]=0;

    int p,q;
    for(int x=0; x<m; x++){
        for(int y=0; y<n; y++){
            p = a[n-y-1]*b[m-x-1];
            q = pmat[x][total-y-1-x] + p;
            pmat[x][total-y-1-x] = q%10;
            pmat[x][total-y-2-x] = q/10;
        }
    }

    for(int y=0; y<total; y++){
        int sum=pdt[total-y-1];
        for(int x=0; x<m; x++){
            sum += pmat[x][total-y-1];
        }
        pdt[total-y-1] = sum%10;
        pdt[total-y-2] = sum/10;
    }

    int index=0;
    while(pdt[index]==0) index++;
    for(int i=index; i<total; i++) cout<<pdt[i]; 
    
    return 0;
}