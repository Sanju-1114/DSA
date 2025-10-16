// leetcode 99

#include <iostream>
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

// TC:O(n)   SC:O(1)
void recoverTree(TreeNode* root) {
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;

    while(root != NULL) {
        if(root->left == NULL){
            if(prev != NULL && prev->val > root->val) {
                if (first == NULL) {
                    first = prev;
                }
                second = root;
            }
            prev = root;
            root = root->right;
        } else {
            //find prev IP
            TreeNode* IP = root->left;
            while(IP->right != NULL && IP->right != root) {
                IP = IP->right;
            }

            if(IP->right == NULL) {
                IP->right = root;  
                root = root->left;
            } else {
                if(prev != NULL && prev->val > root->val) {
                    if (first == NULL) {
                        first = prev;
                    }
                    second = root;
                }
                prev = root;
                IP->right = NULL;
                root = root->right;
            }
        }
    }
    if(first != NULL && second != NULL) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}




// TC:O(n)   SC:O(n)
// namespace {
//     TreeNode* prev = NULL;
//     TreeNode* first = NULL;
//     TreeNode* second = NULL;
// void inorder(TreeNode* root) {
//     if (root == NULL) {
//         return;
//     }
//     inorder(root->left);
//     if (prev != NULL && prev->val > root->val) {
//         if (first == NULL) {
//             first = prev;
//         }
//         second = root;
//     }
//     prev = root;
//     inorder(root->right);
// }

// void recoverTree(TreeNode* root) {
//     // inorder traverse => first, second
//     inorder(root);
//     // first, second => swap
//     int temp = first->val;
//     first->val = second->val;
//     second->val = temp;
// }
// }


// Helper function to print the tree in-order
void printInorder(TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Sample BST with swapped nodes
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2); // swapped node

    cout << "Inorder before recovery: ";
    printInorder(root);
    cout << endl;

    recoverTree(root);

    cout << "Inorder after recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}