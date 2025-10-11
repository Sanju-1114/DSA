// leetcode 100
#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};

TreeNode* buildTree(vector<int>& preorder, int& idx) {
    if (idx >= preorder.size() || preorder[idx] == -1) {
        idx++;
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[idx++]);

    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

//identical or Same tree
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL || q == NULL){
        return p == q;
    }     

    bool isLeftSame = isSameTree(p->left , q->left);
    bool isRightSame = isSameTree(p->right , q->right);

    return isLeftSame && isRightSame && (p->val == q->val) ;
}

int main() {
    vector<int> tree1 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> tree2 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    int idx1 = 0, idx2 = 0;
    TreeNode* root1 = buildTree(tree1, idx1);
    TreeNode* root2 = buildTree(tree2, idx2);

    cout << isSameTree(root1, root2) << endl;

    return 0;
}