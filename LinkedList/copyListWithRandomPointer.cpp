//LeetCode Problem 138

#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

// To create node for linked list
class Node{
public:
    int val;
    Node* next;
    Node* random;


    Node(int val){
        this->val = val;
        next = NULL;
        random = NULL;
    }
};

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
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

};

Node* copyRandomList(Node* head){
    if(head == NULL){
        return NULL;
    }

    unordered_map<Node* , Node*>m;

    Node* newHead = new Node(head->val);
    Node* oldTemp = head->next;
    Node* newTemp = newHead;
    m[head] = newHead;

    while(oldTemp != NULL){
        Node* copyNode = new Node(oldTemp->val);
        m[oldTemp] = copyNode;
        newTemp->next = copyNode;

        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    oldTemp = head ; newTemp = newHead;
    while(oldTemp != NULL){
        newTemp->random = m[oldTemp->random];
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    return newHead;
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

    ll.printLL(copyRandomList(ll.headPtr()));
   
    



    return 0;
}
