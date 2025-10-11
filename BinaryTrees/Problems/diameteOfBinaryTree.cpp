//leetcode 543
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

//Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not 
//pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

// int height(TreeNode* root){  //TC : O(n)
    
//     if(root == NULL) return 0;

//     int leftHt = height(root->left);

//     int rightHt = height(root->right);

//     return max(leftHt , rightHt) + 1;
    
// }

// int diameterOfBinaryTree(TreeNode* root) {  //TC: O(n*n)   ==> not most optimized
//     if(root == NULL) {
//         return 0;
//     }
    
//     int leftDia = diameterOfBinaryTree(root->left);
//     int rightDia = diameterOfBinaryTree(root->right);

//     int currDia = height(root->left) + height(root->right);

//     return max(leftDia, max(rightDia, currDia));
// }


int ans = 0;
int height(TreeNode* root){  //TC : O(n)
    
    if(root == NULL) return 0;

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    ans = max(ans , leftHt+rightHt);   // CurrDiam of root node

    return max(leftHt , rightHt) + 1;
    
}

int diameterOfBinaryTree(TreeNode* root) {  //TC: O(n)   
    height(root);

    return ans;
}


int main() {
    vector<int> tree1 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    int idx1 = 0, idx2 = 0;
    TreeNode* root = buildTree(tree1, idx1);

    cout << diameterOfBinaryTree(root)  << endl;

    return 0;
}