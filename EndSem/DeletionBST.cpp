#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
    Node(int val){
    	data=val;
    	left=NULL; right=NULL;
    }
};

void inOrderTraversal(Node* root){
    if(root==NULL) return;
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void insertNode(Node* root, int key){
    Node *prev = NULL;
    while(root != NULL){
        prev = root;
        if(key == root->data){
            cout<<key<<" already in BST"<<endl;
            return;
        }
        else if(key < root->data) root = root->left;
        else root = root->right;
    }
    Node* n = new Node(key);
    if(key<prev->data) prev->left = n;
    else prev->right = n;
}

Node* createBST(int arr[], int n){
    Node* root = new Node(arr[0]);
    for(int i=1; i<n; i++){
        insertNode(root, arr[i]);
    }
    return root;
}

Node* inOrderPredecessor(Node* root){
    root = root->left;
    while (root->right != NULL) root = root->right;
    return root;
}
Node *deleteNode(Node *root, int key){
    if(root == NULL) return NULL;
    if((root->left == NULL)&&(root->right == NULL)){
        free(root);
        return NULL;
    }
    if(key < root->data){
        root-> left = deleteNode(root->left, key);
    }
    else if(key > root->data){
        root-> right = deleteNode(root->right, key);
    }
    else{
        Node* inPred = inOrderPredecessor(root);
        root->data = inPred->data;
        root->left = deleteNode(root->left, inPred->data);
    }
    return root;
}

int main(){
    cout<<"Enter the number of elements in the BST: ";
	int n;
    cin>>n;
    cout<<"Enter the array of elements of BST (1st element is the root): "<<endl;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
	Node* root = createBST(a, n);

    cout<<endl<<"Inorder Traversal of the BST"<<endl;
    inOrderTraversal(root);
    cout<<endl;

	int deleteKey;
	cout<<"Enter the key to delete: ";
	cin>>deleteKey;
    deleteNode(root, deleteKey);
    cout<<"Inorder Traversal after deleting "<<deleteKey<<endl;
    inOrderTraversal(root);
    cout<<endl;
}