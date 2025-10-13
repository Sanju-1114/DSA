#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void getInorder(Node* root, vector<int>& nodes) {
    if(root == NULL) return;

    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}


Node* buildBSTfromSorted(vector<int>& nums, int st, int end) {
    if(st > end) {
        return NULL;
    }
    
    int mid = st + (end-st)/2;
    Node* curr = new Node(nums[mid]);

    curr->left = buildBSTfromSorted(nums, st, mid-1);
    curr->right = buildBSTfromSorted(nums, mid+1, end);

    return curr;
}


Node* balancedBST(Node* root) {
    //get inorder seq
    vector<int> nodes;
    getInorder(root, nodes);

    //build BST from sorted 
    return buildBSTfromSorted(nodes, 0, nodes.size()-1);

}

void preorder(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


int main() {
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    root = balancedBST(root);

    preorder(root);

    return 0;
}