#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
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

//count  nodes of tree
int count(Node* root){
    
    if(root == NULL) return 0;

    // count nodes of left subtree
    int leftCount = count(root->left);

    // count nodes of right subtree
    int rightCount = count(root->right);

    return leftCount + rightCount + 1;
    
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);

    cout << "Count of Nodes : " << count(root) << endl;

    return 0;
}