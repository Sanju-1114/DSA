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

int  prevOrder = 0;
int kthSmallest(TreeNode* root, int k) {
    if(root == NULL) {
        return -1;
    }

    if(root->left != NULL) {
        int leftAns = kthSmallest(root->left, k);
        if(leftAns != -1) {
            return leftAns;
        }
    }
    
    if(prevOrder + 1 == k) {
        return root->val;
    }
    
    prevOrder = prevOrder + 1;

    if(root->right != NULL) {
        int rightAns = kthSmallest(root->right, k);
        if(rightAns != -1) {
            return rightAns;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    TreeNode* root = buildBST(arr);

    cout << kthSmallest(root, 4);

    return 0;
}