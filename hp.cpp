#include<iostream>
using namespace std;
void insheap(int arr[], int n, int item){
    n=n+1;
    int ptr=n;
    while (ptr>1)
    {
        int par=ptr/2;
        if (item<=arr[par])
        {
            arr[ptr]=item;
            return;
        }
        arr[ptr]=arr[par];
        ptr=par;
    }
    arr[1]=item;
    return;
}
int main(){
    int n;
    int tree[n];
    
    insheap(tree,0,5);
    insheap(tree,1,8);
    insheap(tree,2,2);
    

    for (int n = 1; n <=3; n++)
    {
        cout<<tree[n]<<" ";
    }
    
    return 0;
}