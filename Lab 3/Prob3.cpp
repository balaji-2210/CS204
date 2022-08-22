#include <bits/stdc++.h>
using namespace std;

int permute(int* arr, int n){
    int i=n;
    while(i){
        i--;
        if(arr[i]>arr[i-1]) break;
    }
    if(i){
        sort(arr+i, arr+n);
        for(int y=i; y<n; y++){
            if(arr[i-1]<arr[y]){
                int temp = arr[i-1];
                arr[i-1] = arr[y];
                arr[y] = temp;
                break;
            }
        }
        return 0;
    }
    return 1;
}

int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int a[n];
    for (int i=0; i<n; i++) cin>>a[i];
    int p;
    for(int j=0; j<k-1; j++){
        p = permute(a,n);
        if(p) break;
    }
    if(p==0){
        for (int i=0; i<n; i++) cout<<a[i]<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}