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
void inorder(node* root){
    if(root == 0)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node* root){
    if(root == 0)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void preorder(node* root){
    if(root == 0)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    node* root = 0;
    root = create();
    cout<<"Root is:"<<root<<endl;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}
