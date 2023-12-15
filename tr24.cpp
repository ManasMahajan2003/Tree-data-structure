//restore bst
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
class node{
    public:
    int data;
    node* left , *right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void calcpointers(node* root, node** first, node** mid , node** last , node** prev){
    if (root==NULL)
    {
        return;
    }
    calcpointers(root->left, first, mid , last , prev);
    if (*prev && root->data<(*prev)->data)
    {
        if (!*first)
        {
            *first=*prev;
            *mid=root;
        }
        else{
            *last=root;
        }
    }
    
}
void restore(node* root){
    node* first, * mid , * last, * prev;
    first=NULL;
    mid=NULL;
    last=NULL;
    prev=NULL;
    calcpointers(root, & first , &mid,&last,&prev);
    //case1
    if (first && last)
    {
        swap(&(first->data),&(last->data));
    }
    else if(first&& mid){
        swap(&(first->data),&(mid->data));
    }
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
    node* root=new node(3);
    root->left=new node(4);
    root->right=new node(2);
    inorder(root);
    cout<<endl;
    restore(root);
    inorder(root);

    return 0;
}