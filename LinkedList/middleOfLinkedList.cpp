//LeetCode Problem 876

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

// // Brute-force approach
// Node* middleOfLinkedList(Node* head){
//     Node* temp = head;
//     Node* middle = head;
//     int totalNode = 0;
//     while(temp != NULL){
//         totalNode++;
//         temp = temp->next;
//     }
//     for(int i=0 ; i<=totalNode ; i++){
//         if (i == totalNode/2){
//            return middle; 
//         }
//         middle = middle->next;
//     }    
// }

// Slow-fast approach      SC:O(1)   TC: O(n)
Node* middleOfLinkedList(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL  && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main(){
    List ll;
  
    ll.push_back(1); 
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5); 
    ll.push_back(6); 
    
    ll.printLL(ll.headPtr());
   
    Node* middleNode =  middleOfLinkedList(ll.headPtr()); //returns middle node

    cout << middleNode->data << endl;


    return 0;
}
