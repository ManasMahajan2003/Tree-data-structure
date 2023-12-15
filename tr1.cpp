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
void inorderprint(node* root){
    if (root==NULL)
    {
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}
int search(int inorder[], int start, int end, int curr){
    for (int i = start; i <=end; i++)
    {
        if (inorder[i]==curr)
        {
            return i;
        }
        
    }
    return -1;
}
node* buildtree(int inorder[] , int preorder[], int start, int end){
    static int idx=0;
    if (start>end)
    {
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    node* Node=new node(curr);
    if (start==end)
    {
        return Node;
    }
    int pos = search(inorder , start , end , curr);
    Node->left=buildtree(inorder, preorder , start, pos-1);
    Node->right=buildtree(inorder, preorder, pos+1, end);
    return Node;
}
void preorderprint(node* root){
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorderprint(root->left);
    
    preorderprint(root->right);
    
}
int main(){
    /*node* root = new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);*/
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    node* root = buildtree(inorder , preorder, 0 , 4);
    inorderprint(root);
    preorderprint(root);
    return 0;
}