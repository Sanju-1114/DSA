// leetcode 572
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

bool isIdenticalTree(TreeNode* p, TreeNode* q) {
    if(p == NULL || q == NULL){
        return p == q;
    }     

    bool isLeftSame = isIdenticalTree(p->left , q->left);
    bool isRightSame = isIdenticalTree(p->right , q->right);

    return isLeftSame && isRightSame && (p->val == q->val) ;
}

//Sub Tree Of Another Tree
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
     if(root == NULL || subRoot == NULL){
        return root == subRoot;
    } 

    if(root->val == subRoot->val && isIdenticalTree(root , subRoot)){
        return true;
    }

    return isSubtree(root->left , subRoot) || isSubtree(root->right , subRoot);
}

int main() {
    vector<int> tree1 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> tree2 = {3, 4, -1, -1, 5, -1, -1};

    int idx1 = 0, idx2 = 0;
    TreeNode* root = buildTree(tree1, idx1);
    TreeNode* subRoot = buildTree(tree2, idx2);

    cout << isSubtree(root , subRoot) << endl;

    return 0;
}