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

// TreeNode* insert(TreeNode* root, int val) {
//     if(root == NULL) {
//         return new TreeNode(val);
//     }

//     if(val < root->val) {
//         root->left = insert(root->left, val);
//     } else {
//         root->right = insert(root->right, val);
//     }

//     return root;
// }

// TreeNode* buildBST(vector<int> arr) {
//     TreeNode* root = NULL;

//     for(int val : arr) {
//         root = insert(root, val);
//     }

//     return root;
// }

TreeNode* helper(vector<int>& preorder, int& i, int bound) {
    if(i >= preorder.size() || preorder[i] > bound) {
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[i]);
    i++;

    root->left = helper(preorder, i, root->val);
    root->right = helper(preorder, i, bound);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return helper(preorder, i, INT32_MAX);
}
    
int main() {
    vector<int> preOrder = {6, 3, 1, 4, 8, 9};

    // TreeNode* root = buildBST(preOrder);

    TreeNode* root = bstFromPreorder(preOrder);
    
    cout << root->val << endl;
    cout << root->left->val << endl;

    return 0;
}