//LeetCode Problem 206

#include<iostream>
#include<algorithm>
using namespace std;

// To create node for linked list
class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

// This is the list for every operation which we have to perform
class List{
    Node *head;
    Node *tail;

public:
    List(){
        head = NULL;
        tail = NULL;
    }  
    
    Node* headPtr(){
        Node* temp = head;
        return temp;
    }

    //Insert at the end (last) of the linked list   TC : O(1) due to tail node else TC : O(n)
    void push_back(int val){
        Node* newNode = new Node(val);
        
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    //Display the linked list     TC : O(n)
    void printLL(Node *head){
        Node* temp = head;
        while (temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

};

// To reverse the Linked List
Node* reverseList(Node* head){     // SC: O(1)    TC : O(n)
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main(){
    List ll;
  
    ll.push_back(5); 
    ll.push_back(4);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1); 

    ll.printLL(ll.headPtr());
    
   Node* newHead =  reverseList(ll.headPtr());

    ll.printLL(newHead);

    return 0;
}
