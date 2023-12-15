//LCA2
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
node* lca(node* root, int n1, int n2){
    if (root==NULL)
    {
        return NULL;
    }
    if (root->data==n1 || root->data==n2)
    {
        return root;
    }
    node* left=lca(root->left, n1, n2);
    node* right=lca(root->right, n1, n2);
    if (left!=NULL && right!=NULL)
    {
        return root;
    }
    if (left==NULL && right==NULL)
    {
        return NULL;
    }
    if (left!=NULL)
    {
        return lca(root->left, n1 , n2);
    }
    return lca(root->right, n1,n2);
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
    node* LCA=lca(root, 6,3);
    cout<<LCA->data;
    return 0;
}