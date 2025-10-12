// leetcode 236
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL){
        return NULL;
    }

    if(root->val == p->val || root->val == q->val){
        return root;
    }

    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    if(leftLCA && rightLCA) {
        return root;
    } else if(leftLCA != NULL) {
        return leftLCA;
    } else {
        return rightLCA;
    }
}

int main() {
    vector<int> preorder = {1, 2, 4, -1, -1, 5, 8, -1, -1, 9, -1, -1, 3, 6, -1, -1, 7, -1, -1};

    TreeNode* root = buildTree(preorder);

    TreeNode* ancestorRoot = lowestCommonAncestor(root, root->left->left, root->left->right->right);

    cout << ancestorRoot->val << endl;

    return 0;
}