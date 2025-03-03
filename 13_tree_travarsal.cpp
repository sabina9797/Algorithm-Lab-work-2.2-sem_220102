#include<bits/stdc++.h>
using namespace std;

struct Node{
   
    int data;
    Node* left;
    Node* right;

    //constructor for set value;
   Node(int val) {
   data = val;
    left = NULL;
    right = NULL;
   }
};
// for insert binary tree
Node* insertBST(Node* root,int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insertBST(root->left,val);

    }
    else{
       root->right = insertBST(root->right,val); 
    }
    return root;
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " "; 
    preorder(root->left);      
    preorder(root->right);     
}
void postorder(Node* root){
    if(root == NULL){
        return;
    }
   postorder(root->left); 
    postorder(root->right);
      cout << root->data << " "; 
}


int main()
{
    Node* root = NULL;
    root = insertBST(root,5);
    root = insertBST(root,1);
    root = insertBST(root,3);
    root = insertBST(root,4);
    root = insertBST(root,2);
    root = insertBST(root,7);
    cout<<"inOrder Way BST"<<endl;
      inorder(root) ;
      cout<<endl;
      cout<<"preOrder Way BST"<<endl;
      preorder(root);
      cout<<endl;
      cout<<"post Order Way BST"<<endl;
      postorder(root);
 
  return 0;
}
 
