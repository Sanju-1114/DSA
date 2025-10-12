// Leetcode 662
#include <iostream>
#include <vector>
#include <queue>
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


int widthOfBinaryTree(TreeNode* root) {
    queue<pair<TreeNode*, unsigned long long int>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while(q.size() > 0){
        int currLevelSize = q.size();
        unsigned long long int stIdx = q.front().second;
        unsigned long long int endIdx = q.back().second;

        maxWidth = max(maxWidth, (int)(endIdx-stIdx+1));

        for(int i=0; i<currLevelSize ; i++){
            auto curr = q.front();
            q.pop();

            if(curr.first->left) {
                q.push({curr.first->left, curr.second*2+1});
            }

            if(curr.first->right) {
                q.push({curr.first->right, curr.second*2+2});
            }
        }
    }
    return maxWidth;
}

int main() {
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 7, -1, -1};

    TreeNode* root = buildTree(preorder);

    cout << widthOfBinaryTree(root) << endl;

    return 0;
}