#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);
    }

    if(val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(vector<int> arr) {
    Node* root = NULL;

    for(int val : arr) {
        root = insert(root, val);
    }

    return root;
}

void inOrder(Node* root) {
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

Node* getInorderSuccessor(Node* root) {  // left most of the right subtree
    while(root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root , int key) { // key => val to delete
    if(root == NULL) {
        return NULL;
    }

    if(key < root->data) {
        root->left = delNode(root->left , key);
    } else if(key > root->data) {
        root->right = delNode(root->right , key);
    } else {
        // key == root->data
         if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
         } else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
         } else { // 2 children
            Node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = delNode(root->right, IS->data);
         }
    }
    return root;
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node* root = buildBST(arr);
    cout << "before : " ;
    inOrder(root);
    cout << endl;
    
    cout << "after : " ;
    delNode(root, 5);
    inOrder(root);

    return 0;
}