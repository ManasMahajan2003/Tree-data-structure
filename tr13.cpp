//print nodes at k distance
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
//CASE1
void printsubtreenodes(node* root, int k){
    if (root==NULL || k<0)
    {
        return;
    }
    if (k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    printsubtreenodes(root->left , k-1);
    printsubtreenodes(root->right,k-1);
}
//CASE2
int nodesatk(node* root,node* target, int k){
    if (root==NULL)
    {
        return -1;
    }
    if (root==target)
    {
        printsubtreenodes(root,k);
        return 0;
    }
    int dl=nodesatk(root->left, target, k);
    if (dl!=-1)
    {
        if (dl+1==k)
        {
            cout<<root->data<<" ";
        }
        else{
            printsubtreenodes(root->right,k-dl-2);
        }
    return 1+dl;
    }
    int dr=nodesatk(root->right, target, k);
    if (dr!=-1)
    {
        if (dr+1==k)
        {
            cout<<root->data<<" ";
        }
        else{
            printsubtreenodes(root->left,k-dr-2);
        }
    return 1+dr;
    }
    return -1;
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
    cout<<nodesatk(root,root->left,3);
    return 0;
}