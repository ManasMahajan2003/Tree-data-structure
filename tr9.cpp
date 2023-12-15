//LCA
#include<iostream>
#include<vector>
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
bool getpath(node* root, int key , vector<int> &path){
    if (root==NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if (root->data==key)
    {
        return true;
    }
    if (getpath(root->left, key, path) || getpath(root->right,key, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}
int lca(node* root, int n1, int n2){
    vector<int> path1,path2;
    if (!getpath(root,n1,path1)||!getpath(root,n2,path2))
    {
        return -1;
    }
    int pc;
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc]!=path2[pc])
        {
            break;
        }
        
    }
    return path1[pc-1];
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
    cout<<lca(root, 9,7);
    return 0;
}