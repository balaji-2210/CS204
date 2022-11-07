// Build an expression tree from the expression string
// Evaluate the value of the expression tree
// Print the inorder, preorder and postorder traversal of the expression tree

#include <bits/stdc++.h>
using namespace std;

struct node{
    char data;
    struct node* left;
    struct node* right;
};

struct node* createNode(char opr, struct node* leftNode, struct node* rightNode){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = opr;
    newNode->left = leftNode;
    newNode->right = rightNode;
    return newNode;
}

struct node* buildSubTree(string s, int start, int end, bool isLeftTree){
    int p1=0, p2=0, notEval=0;
    if((s[start]=='(')&&(s[end]==')')){
        start++;
        end--;
    }
    for(int i=end; i>=start; i--){
        if(s[i]==')') notEval++;
        else if(s[i]=='(') notEval--;
        if(notEval) continue;
        if(((s[i]=='+')||(s[i]=='-'))&&(p1!=0)){
            p1=i+1;
        }
        else if(((s[i]=='*')||(s[i]=='/'))&&(p2!=0)){
            p2=i+1;
        }
    }
    int opr;
    if(p1) opr = p1-1;
    else if(p2) opr = p2-1;
    else{
        struct node* leafNode = (struct node*)malloc(sizeof(struct node*));
        if(isLeftTree) leafNode->data = s[end];
        else leafNode->data = s[start];
        leafNode->left = NULL;
        leafNode->right = NULL;
        return leafNode;
    }
    struct node* leftNode = buildSubTree(s, start, opr-1, true);
    struct node* rightNode = buildSubTree(s, opr+1, end, false);
    struct node* headNode = createNode(s[opr], leftNode, rightNode);
    return headNode;
}

struct node* buildTree(string s){
    int n = s.size();
    int p1=0, p2=0, notEval=0;
    for(int i=n-1; i>=0; i--){
        if(s[i]==')') notEval++;
        else if(s[i]=='(') notEval--;
        if(notEval) continue;
        if(((s[i]=='+')||(s[i]=='-'))&&(p1!=0)){
            p1=i+1;
        }
        else if(((s[i]=='*')||(s[i]=='/'))&&(p2!=0)){
            p2=i+1;
        }
    }
    int opr;
    if(p1) opr = p1-1;
    else if(p2) opr = p2-1;
    struct node* leftNode = buildSubTree(s, 0, opr-1, true);
    struct node* rightNode = buildSubTree(s, opr+1, n-1, false);
    struct node* rootNode = createNode(s[opr], leftNode, rightNode);
    return rootNode;
}

void preOrderTraversal(struct node* head){
    if(head==NULL) return;
    cout<< head->data;
    preOrderTraversal(head->left);
    preOrderTraversal(head->right);
}

void inOrderTraversal(struct node* head){
    if(head==NULL) return;
    inOrderTraversal(head->left);
    cout<< head->data;
    inOrderTraversal(head->right);
}

void postOrderTraversal(struct node* head){
    if(head==NULL) return;
    postOrderTraversal(head->left);
    postOrderTraversal(head->right);
    cout<< head->data ;
}

// int evaluateTree(struct node* root){

// }

int main(){
    string exp;
    cin>>exp;
    struct node* root = buildTree(exp);
    inOrderTraversal(root);
    cout<<endl;
    preOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    cout<<endl;
    // int value = evaluateTree(root)
    // cout<<value<<endl;
    return 0;
}