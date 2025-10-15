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


int minDiffInBST(TreeNode* root) {
    static TreeNode* prev = NULL;
    if(root == NULL) {
        return INT32_MAX;
    }

    int ans = INT32_MAX;

    if(root->left != NULL) {
        int leftMin = minDiffInBST(root->left);
        ans = min(ans, leftMin);
    }
    
    if(prev != NULL) {
        ans = min(ans, root->val - prev->val);
    }
    
    prev = root;

    if(root->right != NULL) {
        int rightMin = minDiffInBST(root->right);
        ans = min(ans, rightMin);
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    TreeNode* root = buildBST(arr);

    int min = minDiffInBST(root);

    cout << min << endl;
    
    return 0;
}