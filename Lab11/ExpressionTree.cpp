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

void it_inOrder(node* x){
    stack<node*> e;
    node *current=x;
    while(current!=NULL || e.empty()==false){
        while(current!=NULL){
            e.push(current);
            current=current->left;
        }
        current=e.top();
        e.pop();
        cout<<current->data<<" ";
        current=current->right;
    }
}

void preOrder(node* x){
    if(x==NULL) return;
    cout<<x->data<<" ";
    preOrder(x->left);
    preOrder(x->right);
}

void it_preOrder(node* x){
    stack<node*> e;
    node *current=x;
    while(current!=NULL || e.empty()==false){
        while(current!=NULL){
            e.push(current);
            cout<<current->data<<" ";
            current=current->left;
        }
        e.pop();
        if(e.empty()) break;
        current=e.top();
        e.pop();
        current=current->right;
    }
}

void postOrder(node* x){
    if(x==NULL) return;
    postOrder(x->left);
    postOrder(x->right);
    cout<<x->data<<" ";
}

void it_postOrder(node* x){
    stack<node*> e;
    node *current=x;
    while(true){
        while(current!=NULL){
            e.push(current);
            e.push(current);
            current=current->left;
        }
        if(e.empty()) break;
        current=e.top();
        e.pop();
        if(!e.empty() && e.top()==current){
            current=current->right;
        }
        else{
            cout<<current->data<<" ";
            current=NULL;
        }
    }
}

int calcValue(node* x){
    int ans;
    if(x==NULL) return 0;
    else if(x->data=='+') ans=(calcValue(x->left))+(calcValue(x->right));
    else if(x->data=='-') ans=(calcValue(x->left))-(calcValue(x->right));
    else if(x->data=='*') ans=(calcValue(x->left))*(calcValue(x->right));
    else if(x->data=='/') ans=(calcValue(x->left))/(calcValue(x->right));
    else ans=int(x->data-'0');
    return ans;
}

int main()
{
    string s;
    cin>>s;
    stack<node*> e;
    node *a,*b,*c;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(') continue;
        else if(s[i]==')'){
            c=e.top();
            e.pop();
            b=e.top();
            e.pop();
            a=e.top();
            e.pop();
            b->left=a;
            b->right=c;
            e.push(b);
        }
        else{
            e.push(new node(s[i]));
        }
    }

    inOrder(b);
    cout<<endl;
    it_inOrder(b);
    cout<<endl;
    preOrder(b);
    cout<<endl;
    it_preOrder(b);
    cout<<endl;
    postOrder(b);
    cout<<endl;
    it_postOrder(b);
    cout<<endl;

    cout<<"The value of the given expression tree is "<<calcValue(b)<<endl;
    return 0;
}