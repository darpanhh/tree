#include<iostream>
using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;
};

Tree* root = nullptr;

void createBST(int item) {
    Tree* newnode = new Tree{item, nullptr, nullptr};
    if (!root) {
        root = newnode;
        return;
    }
    Tree* temp = root;
    while (true) {
        if (item < temp->data) {
            if (!temp->left) {
                temp->left = newnode;
                break;
            }
            temp = temp->left;
        } else {
            if (!temp->right) {
                temp->right = newnode;
                break;
            }
            temp = temp->right;
        }
    }
}

void inorderTraversal(Tree* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Tree* root) {
    if (root) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Tree* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

int main() {
   
    int values[] = {45, 12, 34, 33, 10, 20, 15, 67, 56, 70, 48, 26};
    int size = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < size; i++) {
        createBST(values[i]);
    }

  
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << "\n";

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << "\n";

    return 0;
}

