// given BST and given node find immediate successor node

#include<bits/stdc++.h>
using namespace std;
int successor = 1e9 + 7;
int ans = -1;
class Node {
    public : int key;
             Node* left;
             Node* right;
             Node(int data){
                 key = data;
                 left = NULL;
                 right = NULL;
             }
};

Node* insert(Node* root , int a){
    if(root == NULL){
        root = new Node(a);
        return root;
    }
    
    if(a < root->key){
        root->left = insert(root->left , a);
    }
    else{
        root->right = insert(root->right , a);
    }
    return root;
}
void inorder(Node* root , int k , int prev){
    if(root == NULL){
        return;
    }
    // cout<<prev<<" "<<k<<" "<<root->key<<endl;
    inorder(root->left , k , root->key);
    if((root->key-k) < successor && root->key > k){
        successor = root->key - k;
        ans = root->key;
    }
    cout<<root->key<<"->";
    inorder(root->right , k , root->key);
    return;
}

int main(){
    int n;
    cout<<"Enter number of elements"<<endl;
    cin>>n;
    int a;
    cin>>a;
    vector<int> arr;
    Node* root = new Node(a);
    for(int i = 1 ; i < n ; ++i ) {
        int a;
        cin>>a;
        arr.emplace_back(a);
        root = insert(root , a);
    }
    int k;
    cout<<"Enter key to search and find successor"<<endl;
    cin>>k;
    //Searching for the key
    if(find(arr.begin() , arr.end() , k) == arr.end()){
        cout<<-1<<endl;
        return 0;
    }
    int prev = -1;
    inorder(root , k , prev);
    cout<<"Successor is "<<ans<<endl;
    
    return 0;
}