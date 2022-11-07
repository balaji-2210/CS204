#include <bits/stdc++.h>
using namespace std;

struct node{
    char data;
    struct node* left;
    struct node* right;
};

struct node* makeNode(char op, struct node* a, struct node* b){
    struct node* opr;
    opr->data = op;
    opr->left = a;
    opr->right = b;
    return opr;
}



int main(){
    string s;
    cin>>s;
    int n = s.size();
    cout<<n;
    return 0;
}