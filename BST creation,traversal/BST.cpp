#include<iostream>
using namespace std;
struct Tree{
    int data;
    Tree* left;
    Tree* right;
};
Tree* root =nullptr;
void createBST(int item){
    Tree* newnode = new Tree{item,nullptr,nullptr};
    if(!root){
        root = newnode;
        return;
    }
    Tree* temp = root;
    while(true){
        if(item<temp->data){
            if(!temp->left){
                temp->left=newnode;
                break;
            }
            temp=temp->left;
        }
        else{
            if(!temp->right){
                temp->right=newnode;
                break;
            }
            temp=temp->right;
        }
    }
}
void inorderTraversal(Tree* root){
    if(root){
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
}
void preorderTraversal(Tree* root){
    if(root){
        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(Tree* root){
    if(root){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->data<<" ";
    }
}
void menu(){
    cout<<"\nMain menu:\n";
    cout<<"1)Create BST Tree\n";
    cout<<"2)Inorder traversal of tree\n";
    cout<<"3)Preorder traversal of tree\n";
    cout<<"4)Postorder traversal of tree\n";
    cout<<"5)Exit\n";
}
int main(){
    int choice,item;
    bool flag=true;
    while(flag){
        menu();
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the data to be inserted in the tree: ";
                cin>>item;
                createBST(item);
                break;
            case 2:
                cout<<"Inorder traversal: ";
                inorderTraversal(root);
                cout<<endl;
                break;
            case 3:
                cout<<"Preorder traversal: ";
                preorderTraversal(root);
                cout<<endl;
                break;
            case 4:
                cout<<"Postorder traversal: ";
                postorderTraversal(root);
                cout<<endl;
                break;
            default:
                flag=false;
                cout<<"Invalid choice\n";
                break;
        }
    }
    return 0;
}
