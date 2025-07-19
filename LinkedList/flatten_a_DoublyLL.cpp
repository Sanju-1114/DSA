//LeetCode Problem 430

#include<iostream>
#include<algorithm>
using namespace std;

// To create Node for linked list
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int val){
        data = val;
        next = prev = child = NULL;
    }
};

Node* flatten(Node* head) {
    if(head == NULL){
        return head;
    }   

    Node* curr = head;

    while(curr != NULL){
        if(curr->child != NULL){
            //flatten the child nodes
            Node* next = curr->next;
            curr->next = flatten(curr->child);

            curr->next->prev = curr;
            curr->child = NULL;

            // find the tail
            while(curr->next != NULL){
                curr = curr->next;
            }

            //attach tail with next pointer
            if(next != NULL){
                curr->next = next;
                next->prev = curr;
            }

        }

        curr = curr->next;
    }

    return head;
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main(){
   
    // Creating nodes manually
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->child = new Node(4);
    head->next->child->next = new Node(5);
    head->next->child->next->prev = head->next->child;

    cout << "Original List:" << endl;
    display(head);

    head = flatten(head);
    
    cout << "Flattened List:" << endl;
    display(head);

    return 0;
}
