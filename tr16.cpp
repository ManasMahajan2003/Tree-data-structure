//insert in bst
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* insert(node* root, int key){
    if (root==NULL)
    {
        return new node(key);
    }
    if (key<root->data)
    {
        root->left=insert(root->left,key);
    }
    if (key>root->data)
    {
        root->right=insert(root->right,key);
    }
    return root;
}
node* search(node* root, int key){
    if (root==NULL)
    {
        return NULL;
    }
    if (root->data==key)
    {
        return root;
    }
    else if (root->data>key)
    {
        return search(root->left,key);
    }
    return search(root->right,key);
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
void preorder(node* root){
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    
    preorder(root->right);
}

int main(){
    node* root=NULL;
    root=insert(root, 3);
    insert(root,2);
    insert(root,1);
    insert(root,7);
    insert(root,5);
    insert(root,4);
    insert(root,6);
    insert(root,8);
    preorder(root);
    //inorder(root);
    if (search(root,34)==NULL)
    {
        cout<<"key is not in bst"<<endl;
    }
    else{
        cout<<"key is in bst"<<endl;
    }
    return 0;
}