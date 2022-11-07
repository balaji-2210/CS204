#include <bits/stdc++.h>
using namespace std;
const int N=1e7;
int a[N][3];

int node(int j){
    return a[j][2];
}
int parent(int j){
    return a[j/2][2];
}
int left(int j){
    return a[2*j][2];
}
int right(int j){
    return a[2*j+1][2];
}

void swapNodes(int x, int y){
    for(int t=0; t<3; t++){
        int temp=a[x][t];
        a[x][t]=a[y][t];
        a[y][t]=temp;
    }
}

void minHeapify(int i, int m){
    int smallest = i;
    if((2*i<=m)&&(left(i)<node(smallest))){
        smallest = 2*i;
    }
    if((2*i+1<=m)&&(right(i)<node(smallest))){
        smallest = 2*i+1;
    }
    if(i!=smallest){
        swapNodes(i,smallest);
        minHeapify(smallest,m);
    }
}

void buildMinHeap(int m){
    int t=m/2;
    while(t){
        minHeapify(t,m);
        t--;
    }
}

void printHeap(int m){
    cout<<a[1][0]<<" "<<a[1][1]<<endl;
    if(m==1) return;
    swapNodes(1,m);
    minHeapify(1,m-1);
    printHeap(m-1);
}

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i][0]>>a[i][1];
        a[i][2] = a[i][0]*a[i][0] + a[i][1]*a[i][1];
    }
    buildMinHeap(n);
    // for(int i=1; i<=n; i++){
    //     cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
    // }
    printHeap(n);
    return 0;
}