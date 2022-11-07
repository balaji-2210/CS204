#include <bits/stdc++.h>
using namespace std;

int fact(int f){
    if(f==0 or f==1) return 1;
    return f*fact(f-1);
}

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
    int n;
    cin>>n;
    int a[n],b[n];
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++){
        b[i]=a[i];
    }
    sort(b,b+n);
    int m = fact(n);
    int x,p,c=0;
    for(x=1; x<m; x++){
        for(int j=0; j<n; j++){
            if(a[j]!=b[j]) c++;
        }
        if(c) c=0;
        else break;
        p = permute(b,n);
    }
    cout<<x;
    return 0;
}