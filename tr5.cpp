//sum
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
void sumrep(node* root){
    if (root==NULL)
    {
        return ;
    }
    sumrep(root->left);
    sumrep(root->right);
    if (root->left!=NULL)
    {
        root->data+=root->left->data;
    }
    if (root->right!=NULL)
    {
        root->data+=root->right->data;
    }
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
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    root->left->left->left=new node(8);
    root->right->left->right=new node(9);
    /*
             1
           /   \
          2     3
         / \   /  \
        4   5 6    7
       /       \
      8         9       
    */
    preorder(root);
    cout<<endl;
    sumrep(root);
    preorder(root);
    return 0;
}