//BALANCED HEIGHT TREE
#include<iostream>
#include<algorithm>
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
int height(node* root){
    if (root==NULL)
    {
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh, rh)+1;
    
}
bool isbalanced(node* root){
    if (root==NULL)
    {
        return true;
    }
    if (isbalanced(root->left)==false)
    {
        return false;
    }
    if (isbalanced(root->right)==false)
    {
        return false;
    }
    int lh =height(root->left);
    int rh=height(root->right);
    if (abs(lh-rh)<=1)
    {
        return true;
    }
    else{
        return false;
    }
    
}

bool isbalanced2(node* root , int* height){
    if (root==NULL)
    {
        *height=0;
        return true;
    }
    int lh=0;
    int rh=0;
    if (isbalanced2(root->left,&lh)==false)
    {
        return false;
    }
    if (isbalanced2(root->right,&rh)==false)
    {
        return false;
    }
    *height=lh+rh+1;
    if (abs(lh-rh)<=1)
    {
        return true;
    }
    else{
        return false;
    }
    
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
    root->right->left->right->left=new node(9);
    int height=0;
    if (isbalanced2(root,&height))
    {
        cout<<"balanced tree";
    }
    else{
        cout<<"not balanced";
    }
    return 0;
}