// leetcode 257
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

void allPaths(TreeNode* root, string path, vector<string>& ans) {
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(path);
        return;
    }

    if(root->left){
        allPaths(root->left, path + "->" + to_string(root->left->val), ans);
    }

    if(root->right){
        allPaths(root->right, path + "->" + to_string(root->right->val), ans);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;     
    string path = to_string(root->val); 

    allPaths(root, path, ans);

    return ans;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    TreeNode* root = buildTree(preorder);

    preOrder(root);
    cout << endl;

    for(auto path : binaryTreePaths(root)){
        cout << path << endl;
    }

    return 0;
}