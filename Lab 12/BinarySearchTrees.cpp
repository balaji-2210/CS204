// All the data is given
// No input is needed
#include <bits/stdc++.h>
using namespace std;

// Defining a node
struct node{
	int data;
	struct node* left;
    struct node* right;
};
// Creating a new node
struct node* newNode(int data){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
    n->right = NULL;
	return n;
}

// Traversal of the BST
void inOrderTraversal(struct node* root){
    if(root==NULL) return;
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
void preOrderTraversal(struct node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(struct node* root){
    if(root==NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

// Searching a Key
struct node * searchNode(struct node* root, int key){
    if(root == NULL) return NULL;
    if(key == root->data) return root;
    else if(key < root->data) return searchNode(root->left, key);
    else return searchNode(root->right, key);
}

// Inserting a Key
void insertNode(struct node* root, int key){
    struct node *prev = NULL;
    while(root != NULL){
        prev = root;
        if(key == root->data){
            cout<<key<<" already in BST"<<endl;
            return;
        }
        else if(key < root->data) root = root->left;
        else root = root->right;
    }
    struct node* n = newNode(key);
    if(key<prev->data) prev->left = n;
    else prev->right = n;
}

// Creating the BST from an array
// 1st element is the root and the other elements are inserted one by one
struct node* createBST(int arr[], int n){
    struct node* root = newNode(arr[0]);
    for(int i=1; i<n; i++){
        insertNode(root, arr[i]);
    }
    return root;
}

// Deleting a Key
struct node* inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right != NULL) root = root->right;
    return root;
}
struct node *deleteNode(struct node *root, int key){
    struct node* inPred;
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
        inPred = inOrderPredecessor(root);
        root->data = inPred->data;
        root->left = deleteNode(root->left, inPred->data);
    }
    return root;
}

// Updating a Key with a Value
void updateNode(struct node* root, int key, int value){
    deleteNode(root, key);
    insertNode(root, value);
}



int main(){
    // Building the BST
    cout<<"Enter the number of elements in the BST: ";
	int n;
    cin>>n;
    cout<<"Enter the array of elements of BST (1st element is the root): "<<endl;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
	struct node* root = createBST(a, n);

    // Keys
    int searchKey = 25;
    int insertKey = 30;
    int deleteKey = 25;
    int updateKey = 20, updateValue = 80;

    // Traversing the BST
    cout<<endl<<"Traversing the BST"<<endl;
    inOrderTraversal(root);
    cout<<endl;
    preOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    cout<<endl;

    // Searching an element
    cout<<endl<<"Searching "<<searchKey<<endl;
    struct node* w = searchNode(root, searchKey);
    if(w != NULL) cout<<w->data<<endl;
    else cout<<"key not found"<<endl;
    inOrderTraversal(root);
    cout<<endl;

    // Inserting an element
    cout<<endl<<"Inserting "<<insertKey<<endl;
    insertNode(root, insertKey);
    inOrderTraversal(root);
    cout<<endl;

    // Deleting an element
    cout<<endl<<"Deleting "<<deleteKey<<endl;
    deleteNode(root, deleteKey);
    inOrderTraversal(root);
    cout<<endl;

    // Updating an element
    cout<<endl<<"Updating "<<updateKey<<" to "<<updateValue<<endl;
    updateNode(root, updateKey, updateValue);
    inOrderTraversal(root);
    cout<<endl;
}
