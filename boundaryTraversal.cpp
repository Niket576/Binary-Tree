#include<iostream>
#include <bits/stdc++.h>
#include<queue>
using namespace std;

class Node{ //this is a TreeNode
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* construct(int arr[],int n) {
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>0 && i<n) {
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i] != INT_MIN) l=new Node(arr[i]);
        else l=NULL;
        if(j != n && arr[j] != INT_MIN) r=new Node(arr[j]);
        else r=NULL;
        temp->left = l;
        temp->right = r;
        if(l != NULL) q.push(l);
        if(r != NULL) q.push(r);
        i += 2;
        j += 2;
    }
    return root;
}
void leftBoundary(Node* root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right==NULL) return;
    cout<<root->val<<" ";
    leftBoundary(root->left);
    if(root->left == NULL) leftBoundary(root->right);
}
void bottomBoundary(Node* root) {   //for printing the leaf node
    if(root==NULL) return;
    if(root->left== NULL && root->right==NULL) cout<<root->val<<" ";
    bottomBoundary(root->left);
    bottomBoundary(root->right);
}
void rightBoundary(Node* root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right==NULL) return;
    rightBoundary(root->right);
    if(root->right == NULL) rightBoundary(root->left);
    cout<<root->val<<" ";   //for printing in reverse order- this is post order traversal
}


void boundary(Node* root) {
    leftBoundary(root);
    bottomBoundary(root);   //i.e leaf node printing
    rightBoundary(root);
}

int main() {
    //construct the binary tree
    int arr[] = {1,7,9,2,6,INT_MIN,0,INT_MIN,INT_MIN,8,7,13,INT_MIN};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    boundary(root);
    
}