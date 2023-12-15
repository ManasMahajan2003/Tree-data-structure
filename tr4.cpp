#include<iostream>
#include<queue>
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
//LEVEL ORDER TRAVERSAL
void printlevelorder(node* root){
    if (root==NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* Node = q.front();
        q.pop();
        if (Node!=NULL)
        {
            cout<<Node->data<<" ";
            if (Node->left)
            {
                q.push(Node->left);
            }
            if (Node->right)
            {
                q.push(Node->right);
            }
            
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
        
    }
}
int sumatk(node* root , int k){
    if (root==NULL)
    {
        return -1;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;
    while (!q.empty())
    {
        node* Node=q.front();
        q.pop();
        if (Node!=NULL)
        {
            if (level==k)
            {
                sum+=Node->data;
            }
            if (Node->left)
            {
                q.push(Node->left);
            }
            if (Node->right)
            {
                q.push(Node->right);
            }
            
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
        
    }
    return sum;
}
int count(node* root){
    if (root==NULL)
    {
        return 0;
    }
    return count(root->left) + count(root->right)+ 1;
}
int sum(node* root){
    if (root==NULL)
    {
        return 0;
    }
    return sum(root->left) + sum(root->right)+ root->data;
}
int height(node* root){
    if (root==NULL)
    {
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}
int diameter(node*  root){
    if (root==NULL)
    {
        return 0;
    }
    int lheight=height(root->left);
    int rheight = height(root->right);
    int currdiameter= lheight+rheight+1;
    int ldiameter= diameter(root->left);
    int rdiameter= diameter(root->right);
    return max(currdiameter,max(ldiameter,rdiameter));
}
int diam(node* root, int* height){
    if (root==NULL)
    {
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    
    
    int ld=diam(root->left, &lh);
    int rd=diam(root->right, &rh);
    int currdiam=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(max(ld,rd),currdiam);
}
int main(){
    node* root = new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    printlevelorder(root);
    cout<<endl<<sumatk(root, 2);
    cout<<endl<<count(root);
    cout<<endl<<sum(root);
    cout<<endl<<height(root);
    int height=0;
    cout<<endl<<diam(root,&height);
return 0;
}