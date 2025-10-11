#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;

    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]); // Root

    root->left = buildTree(preorder);  //left subtree
    root->right = buildTree(preorder); // right subtree

    return root;

}

//height of tree
int height(Node* root){
    
    if(root == NULL) return 0;

    // height of left subtree
    int leftHt = height(root->left);

    // height of right subtree
    int rightHt = height(root->right);

    return max(leftHt , rightHt) + 1;
    
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);

    cout << "height : " << height(root) << endl;

    return 0;
}