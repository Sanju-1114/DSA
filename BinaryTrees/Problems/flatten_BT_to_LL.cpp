// leetcode 114
#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        val = value;
        left = right = NULL;
    }
};

static int idx = -1;
TreeNode* buildTree(vector<int> preorder){
    idx++;

    if(preorder[idx] == -1) return NULL;

    TreeNode* root = new TreeNode(preorder[idx]); // Root

    root->left = buildTree(preorder);  //left subtree
    root->right = buildTree(preorder); // right subtree

    return root;

}

//preorder traversal
void preOrder(TreeNode* root) {
    if(root == NULL) return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

TreeNode* nextRight = NULL;   // next right => last visited node   
void flatten(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    flatten(root->right);
    flatten(root->left);

    root->left = NULL;
    root->right = nextRight;
    nextRight = root;
    
}

int main() {
    vector<int> preorder = {1, 2,  3, -1, -1, 4, -1, -1, 5, -1, 6, -1, -1};

    TreeNode* root = buildTree(preorder);

    cout << root->right->val << endl;

    flatten(root);

    cout << root->right->val << endl;   // 2 instead of 5 which proves it flattened

    return 0;
}