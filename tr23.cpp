//largest bst in bt
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
class info{
    public:
    int size;
    int max;
    int min;
    int ans;
    bool isbst;
};
info largestBSTinBT(node* root){
    if (root==NULL)
    {
        return {0,INT16_MIN,INT16_MAX,0,true};
    }
    if (root->left==NULL &&root->right==NULL)
    {
        return {1,root->data,root->data,1,true};
    }
    info leftinfo=largestBSTinBT(root->left);
    info rightinfo=largestBSTinBT(root->right);
    info curr;
    curr.size= 1+leftinfo.size+rightinfo.size;
    if (leftinfo.isbst &&rightinfo.isbst && leftinfo.max<root->data && rightinfo.min>root->data)
    {
        curr.min=min(leftinfo.min,min(rightinfo.min,root->data));
        curr.max=max(rightinfo.max,max(leftinfo.max,root->data));
        curr.ans =curr.size;
        curr.isbst=true;
        return curr; 
    }
    curr.ans=max(leftinfo.ans,rightinfo.ans);
    curr.isbst=false;
    return curr;
}
int  main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->right->left=new node(4);
    root->right->right=new node(5);
    cout<<"size of largest bst in bt is: "<<largestBSTinBT(root).ans;
    return 0;
}