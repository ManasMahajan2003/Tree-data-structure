//maximum pathsum of a tree
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
int maxpathsumutil(node* root,int &ans){
    if (root==NULL)
    {
        return 0;
    }
    int left=maxpathsumutil(root->left,ans);
    int right=maxpathsumutil(root->right,ans);
    int nodemax=max(max((root->data),(root->data+left+right)),max((root->data+left),(root->data+right)));
    ans= max(ans,nodemax);
    int singlepathsum=max((root->data),max((root->data + left),(root->data+right)));
    return singlepathsum;
}
int maxpathsum(node* root){
    int ans=INT16_MIN;
    maxpathsumutil(root,ans);
    return ans;
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
    
    cout<<maxpathsum(root);
    return 0;
}