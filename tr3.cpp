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
int search(int inorder[] ,int start,int end , int val){
    for (int i = start; i <=end; i++)
    {
        if (inorder[i]==val)
        {
            return i;
        }
        
    }
    return -1;
    
}
node* buildtree(int postorder[], int inorder[], int start, int end){
    static int idx=4;
    if (start>end)
    {
        return NULL;
    }
    int val=postorder[idx];
    idx--;
    node* curr= new node(val);
    if (start==end)
    {
        return curr;
    }
    int pos= search(inorder, start, end, val);
    curr->right=buildtree(postorder , inorder, pos+1, end);
    curr->left=buildtree(postorder, inorder, start, pos-1);
    return curr;
}
void inorderprint(node* root){
    if (root==NULL)
    {
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
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
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};
    node* newroot = buildtree(postorder , inorder , 0 , 4);
    inorderprint(newroot);
    preorderprint(newroot);

    return 0;
}