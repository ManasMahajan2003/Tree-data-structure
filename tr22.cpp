//are bst identical
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
    if (root->data>val)
    {
        root->left=insert(root->left,val);
    }
    if (root->data<val)
    {
        root->right=insert(root->right,val);
    }
    return root;
}
bool isidentical(node* root1, node* root2){
    if (root1==NULL && root2==NULL)
    {
        return true;
    }
    else if (root1==NULL || root2==NULL)
    {
        return false;
    }
    else{
        bool cond1= root1->data==root2->data;
        bool cond2= isidentical(root1->left , root2->left);
        bool cond3= isidentical(root1->right,root2->right);
        if (cond1 && cond2 && cond3)
        {
            return true;
        }
        return false;
    }
}
int main(){
    node* root=NULL;
    root=insert(root, 5);
    insert(root,3);
    insert(root,19);
    insert(root,1);
    insert(root,4);
    node* root2=NULL;
    root2=insert(root2,5);
    if (isidentical(root,root2))
    {
        cout<<"is identcal"<<endl;
    }
    else{
        cout<<"not identical"<<endl;
    }
    return 0;
}