#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

void inOrder(TreeNode* root) {
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

TreeNode* helper(vector<int>& nums, int st, int end) {
    if(st > end) {
        return NULL;
    }
    
    int mid = st + (end-st)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums, st, mid-1);
    root->right = helper(nums, mid+1, end);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size()-1);
}

int main() {
    vector<int> arr = {-10, -3, 0, 5, 9};

    TreeNode* root = sortedArrayToBST(arr);

    inOrder(root);

    return 0;
}