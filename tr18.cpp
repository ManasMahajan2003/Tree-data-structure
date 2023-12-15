//build bst from preorder
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
node* insert (node* root, int val){
    if (root==NULL)
    {
        return new node(val);
    }
    if (val<root->data)
    {
        root->left=insert(root->left,val);
    }
    if (val>root->data)
    {
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
node* build(int pre[], int * preidx, int key, int min , int max, int n){
    if (*preidx>=n)
    {
        return NULL;
    }
    node* root=NULL;
    if (key>min && key<max)
    {
        root=new node(key);
        *preidx=*preidx +1;
        if (* preidx<n)
        {
            root->left=build(pre,preidx,pre[*preidx],min , key,n);
        }
        if (*preidx<n)
        {
            root->right=build(pre,preidx,pre[*preidx],key,max,n);
        }
        
    }
    return root;
    
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
    
    int pre[]={3,2,1,7,5,4,6,8};
    int n=8;
    int preidx=0;
    node* root=build(pre,&preidx,pre[0],INT16_MIN,INT16_MAX,n);
    preorder(root);
    cout<<endl;
    inorder(root);
    return 0;
}