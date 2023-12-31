//zigzag traversal
#include<iostream>
#include<stack>
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
void zigzag(node* root){
    if (root==NULL)
    {
        return;
    }
    stack<node*> currlevel;
    stack<node*> nextlevel;
    bool lefttoright=true;
    currlevel.push(root);
    while (!currlevel.empty())
    {
        node* temp=currlevel.top();
        currlevel.pop();
        if (temp)
        {
            cout<<temp->data<<" ";
            if (lefttoright)
            {
                if (temp->left)
                {
                    nextlevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextlevel.push(temp->right);
                }
                
            }
            else{
                if (temp->right)
                {
                    nextlevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextlevel.push(temp->left);
                }
                
            }
        }
        if (currlevel.empty())
        {
            lefttoright=!lefttoright;
            swap(currlevel,nextlevel);
        }
        
    }
    
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
    zigzag(root);
    return 0;
}