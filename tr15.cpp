//BST
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left, *right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* insert(node* root, int val){
    if (root==NULL)
    {
        return new node(val);
    }
    if(val<root->data){
    root->left=insert(root->left, val);
    }
    else{
    root->right=insert(root->right,val);
    }
    return root;
}
void inorder(node* root){
    if (root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    node* root=NULL;
    root=insert(root, 5);
    insert(root,3);
    insert(root,19);
    insert(root,1);
    insert(root,4);
    inorder(root);
    
    return 0;
}