#include <iostream>
#include <vector>
#include <queue>
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

// //Level Order traversal   => using iterative method
// void levelOrderTraversal(Node* root){
//     queue <Node*> q;

//     q.push(root);

//     while(q.size() > 0){
//         Node* curr = q.front();
//         q.pop();

//         cout << curr->data << " ";

//         if(curr->left != NULL){
//             q.push(curr->left);
//         } 
//         if(curr->right != NULL){
//             q.push(curr->right);
//         } 
//     }
//     cout << endl;

// }
//Level Order traversal   => using iterative method and -> (print the data of different data on different line)
void levelOrderTraversal(Node* root){
    queue <Node*> q;

    q.push(root);
    q.push(NULL);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }

        cout << curr->data << " ";

        if(curr->left != NULL){
            q.push(curr->left);
        } 
        if(curr->right != NULL){
            q.push(curr->right);
        } 
    }
    cout << endl;

}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);

    levelOrderTraversal(root);
    cout << endl;


    return 0;
}