#include <iostream>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// Standalone function version of connect
Node* connect(Node* root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // mark the end of a level

    Node* prev = NULL;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            if (q.empty()) {
                break;
            }
            q.push(NULL);
        } else {
            if (curr->left != NULL) {
                q.push(curr->left);
            }

            if (curr->right != NULL) {
                q.push(curr->right);
            }

            if (prev != NULL) {
                prev->next = curr;
            }
        }
        prev = curr;
    }

    return root;
}

int main() {
    // Create a simple perfect binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Connect the nodes
    connect(root);

    // Output the next pointers level by level
    Node* level = root;
    while (level != NULL) {
        Node* curr = level;
        while (curr != NULL) {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
        level = level->left;
    }

    return 0;
}