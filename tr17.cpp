//delete in bst
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left, * right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }  
};
node* inordersucc(node* root){
    node* curr=root;
    while (curr&&curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}
node* insert(node* root, int val){
    if (root==NULL)
    {
        return new node(val);
    }
    if (root->data>val)
    {
        root->left=insert(root->left, val);
    }
    if(root->data<val){
    root->right=insert(root->right,val);
    }
    return root;
}
node* del(node* root,int key){
    if (key<root->data)
    {
        root->left=del(root->left,key);
    }
    else if (key>root->data)
    {
        root->right=del(root->right,key);
    }
    else{
        if (root->left==NULL)
        {
            node* temp=root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL)
        {
            node* temp= root->left;
            free(root);
            return temp;
        }
        node* temp=inordersucc(root->right);
        root->data=temp->data;
        root->right=del(root->right,temp->data);
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
    del(root,5);
    cout<<endl;
    inorder(root);
    return 0;
}