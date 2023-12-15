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
bool isbst(node* root, node* min =NULL, node* max=NULL){
    if (root==NULL)
    {
        return true;
    }
    if (min!=NULL && root->data<min->data)
    {
        return false;
    }
    if (max!=NULL && root->data>max->data)
    {
        return false;
    }
    bool leftvalid=isbst(root->left,min,root);
    bool rightvalid=isbst(root->right,root,max);
    return leftvalid and rightvalid;
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
    if (isbst(root,NULL,NULL))
    {
        cout<<"bst"<<endl;
    }
    else{
        cout<<"not bst"<<endl;
    }
    return 0;
}