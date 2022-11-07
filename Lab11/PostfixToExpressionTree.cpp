#include<bits/stdc++.h>
using namespace std;

struct node{
    char data;
    node* left;
    node* right;
    node(char val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void inOrder(node* x){
    if(x==NULL) return;
    inOrder(x->left);
    cout<<x->data<<" ";
    inOrder(x->right);
}

int main()
{
    string s;
    cin>>s;
    stack<node*> e;
    node *a,*b,*c;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            b=e.top();
            e.pop();
            a=e.top();
            e.pop();
            c=new node(s[i]);
            c->left=a;
            c->right=b;
            e.push(c);
        }
        else{
            e.push(new node(s[i]));
        }
    }

    inOrder(c);
    cout<<endl;
    
    return 0;
}