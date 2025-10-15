#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
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

class Info {
public:    
    int min, max, size;

    Info(int mn, int mx, int sz) {
        min = mn;
        max = mx;
        size = sz;
    }
};

Info helper(TreeNode* root) {
    if(root == NULL) {
        return Info(INT32_MAX, INT32_MIN, 0);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->data > left.max && root->data < right.min) {
        int currMin = min(root->data, left.min);
        int currMax = max(root->data, right.max);
        int currSize = left.size + right.size + 1;
        
        return Info(currMin, currMax, currSize);
    }

    return Info(INT32_MIN, INT32_MAX, max(left.size, right.size));
}

// Find size of largest BST in BT
int largestBSTinBT(TreeNode* root) {
    Info info = helper(root);

    return info.size;  // max BST size
}

int main() {
    vector<int> preorder = {10, 5, 1, -1, -1, 8, -1, -1, 15, -1, 7, -1, -1};

    TreeNode* root = buildTree(preorder);

    // cout << root->data << endl;
    // cout << root->left->data << endl;
    // cout << root->right->data << endl;

    cout << largestBSTinBT(root) << endl;

    return 0;
}