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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if (root == NULL) {
            return NULL;
        }

        if (root->val > p->val && root->val > q->val) { // left subtree
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val) { // right subtree
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    
}

    
int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    TreeNode* root = buildBST(arr);

    

    return 0;
}