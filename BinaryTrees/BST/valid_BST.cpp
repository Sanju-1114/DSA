#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int val) {
    if(root == NULL) {
        return new TreeNode(val);
    }

    if(val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

TreeNode* buildBST(vector<int> arr) {
    TreeNode* root = NULL;

    for(int val : arr) {
        root = insert(root, val);
    }

    return root;
}

void inOrder(TreeNode* root) {
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
    if(root == NULL) {
        return true;
    }

    if(min != NULL && root->val <= min->val) {
        return false;
    }
    
    if(max != NULL && root->val >= max->val) {
        return false;
    }

    return helper(root->left, min, root) && helper(root->right, root, max);
}

bool isValidBST(TreeNode* root) {
    return helper(root, NULL, NULL);
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    TreeNode* root = buildBST(arr);

    // inOrder(root);

    cout << isValidBST(root);

    return 0;
}