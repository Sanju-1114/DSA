//Circular Linked List

#include<iostream>
#include<algorithm>
using namespace std;

class Node{
public:    
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};


class CircularList {
    Node* head;
    Node* tail;

public:
    CircularList(){
        head = tail = NULL;
    }   
    
    void insertAtHeadt(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        }else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
       
    }

    void insertAtTail(int val){
        Node* newNode = new Node(val);
        
        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        }else{
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
           
    }

    void deleteAtHead(){
        if (head == NULL){
            cout << "Nothing to delete (Circular LL is empty)" << endl;
            return;
        }
        if(head == tail){
            delete head;
            tail = head = NULL;
            cout << "Now Circular LL is empty" << endl;
            return;
        }else{
            Node* temp = head;
            head = head->next;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }        
    }

    void deleteAtTail(){
        if (head == NULL){
            cout << "Nothing to delete (Circular LL is empty)" << endl;
            return;
        }
        else if(head == tail){
            delete head;
            tail = head = NULL;
            cout << "Now Circular LL is empty" << endl;
        }else{
            Node* temp = tail;
            Node* prev = head;
            
            while(prev->next != tail){
                prev = prev->next;
            }

            tail = prev;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        } 
    };

    void print(){
        if (head == NULL) return;

        cout << head->data << " -> ";
        Node* temp = head->next;
        
        while (temp != head){
            cout << temp->data << " -> ";
            temp = temp->next;
        }     
        cout << temp->data << endl;;        
    }
};

int main(){
    CircularList cll;

    // cll.insertAtHeadt(1);
    // cll.insertAtHeadt(2);
    // cll.insertAtHeadt(3);

    cll.insertAtTail(1);
    cll.insertAtTail(2);
    cll.insertAtTail(3);
    
    cll.print();
    
    // cll.deleteAtHead();
    cll.deleteAtTail();

    cll.print();

    return 0;
}