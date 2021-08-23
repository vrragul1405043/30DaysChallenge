#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int val){
    struct Node* temp = new Node();
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct Node* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

void postorder(struct Node* root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}

void preorder(struct Node* root){
    if(root==NULL)return;
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

void levelorder(struct Node* root){
    if(!root)return;
    queue<Node*>q;
    vector<vector<int>>ans;
    q.push(root);
    while(!q.empty()){
        int SIZE = q.size();
        vector<int>level;
        for(int i=0;i<SIZE;++i){
            Node* temp = q.front();
            q.pop();
            level.push_back(temp->data);
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        ans.push_back(level);
    }//end while
     for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<"\t";
        }
        cout<<endl;
    }
}//end func


int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    cout<<"INORDER"<<endl;
    inorder(root);
    cout<<"POST-ORDER"<<endl;
    postorder(root);
    cout<<"PRE-ORDER"<<endl;
    preorder(root);
    cout<<"LEVEL-ORDER"<<endl;
    levelorder(root);
    return 0;
}
