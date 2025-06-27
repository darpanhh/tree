#include<iostream>
using namespace std;
struct node{
    int data;
    node* left,*right;
};
node* create(){
    int x;
    node* newnode = new node;
    cout<<"Enter data(-1 for no node)"<<endl;
    cin>>x;
    if(x==-1){
        return 0;
    }
    newnode->data = x;
    cout<<"Enter left child of"<<x<<endl;
    newnode->left = create();
    cout<<"Enter right child of"<<x<<endl;
    newnode->right = create();
    return newnode;
}
int main(){
    node* root = 0;
    root = create();

    return 0;
}
