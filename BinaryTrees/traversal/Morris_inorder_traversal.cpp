// leetcode 94
#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int value){
        val = value;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;

    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]); // Root

    root->left = buildTree(preorder);  //left subtree
    root->right = buildTree(preorder); // right subtree

    return root;

}

//inorder traversal
vector<int> inOrderTraversal(Node* root){
    vector<int> ans;
    Node* curr = root;

    while(curr != NULL) {
        if(curr->left == NULL) {
            ans.push_back(curr->val);
            curr = curr->right;
        } else {
            // find the inorder predecessor (IP)
            Node* IP = curr->left;
            while(IP->right != NULL && IP->right != curr) {
                IP = IP->right;
            }

            if(IP->right == NULL) {
                IP->right = curr;  // create
                curr = curr->left;
            } else {
                IP->right = NULL;  // destroy
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return ans;
}

int main() {

    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    // vector<int> preorder = {10, 5, 3, -1, -1, 7, -1, -1, 15, 12, -1, -1, 18, -1, -1};

    Node* root = buildTree(preorder);

    for(auto val: inOrderTraversal(root)) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}