// leetCode 173

#include <iostream>
#include <stack>
using namespace std;

/** Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/** BSTIterator Class */
class BSTIterator {
public:
    stack<TreeNode*> s;

    void storeLeftNodes(TreeNode* root) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) { 
        storeLeftNodes(root);
    }

    int next() { // O(1)
        TreeNode* ans = s.top();
        s.pop();
        storeLeftNodes(ans->right);
        return ans->val;
    }

    bool hasNext() { 
        return s.size() > 0;
    }
};

/** Main Function */
int main() {
    // Sample BST:
    //       10
    //      /  \
    //     5    15
    //         / \
    //        12  18

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15, new TreeNode(12), new TreeNode(18));

    // Instantiate and use BSTIterator
    BSTIterator* obj = new BSTIterator(root);

    cout << "BST In-Order Traversal using Iterator:\n";
    while (obj->hasNext()) {
        cout << obj->next() << " ";
    }
    cout << endl;

    // Cleanup
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;
    delete obj;

    return 0;
}