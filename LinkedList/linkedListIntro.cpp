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

    //Insert at the front of the linked list  TC : O(1)
    void push_front(int val){
        Node* newNode = new Node(val);
        
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;

        }
    }
    
    //Insert at the middle of the linked list       TC : O(n)
    void push_in_middle(int val , int pos){
        if(pos < 0){
            cout << "Insertion not possible for negative positions\n";
            return;
        }
        if (pos == 0){
            push_front(val);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos-1; i++){
            if(temp == NULL){
                cout << "Invalid position" << endl;
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
           
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

    
    //Delete from the front of the linked list      TC : O(1)
    void pop_front(){

        if(head == NULL){
            cout << "Nothing to delete (LL is empty)" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL;

        delete(temp);
        
    }
    
    //Delete from the end(last) of the linked list   TC : O(n)
    void pop_back(){

        if(head == NULL){
            cout << "Nothing to delete (LL is empty)" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != tail){
            temp = temp->next;
        }

        temp->next = NULL;
        delete(tail);

        tail = temp;        
    }

    //Display the linked list     TC : O(n)
    void printLL(){
        Node* temp = head;
        while (temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Search in linked list    TC : O(n)
    void search_in_LL(int val){
        Node* temp = head;
        int pos = 0;
        while(temp != NULL){
            if(temp->data == val){
                cout << "The value " << val << "Found at position : " << pos+1 << endl; 
                return;
            }

            temp = temp->next;
            pos++;
            
        }
        cout << "Data not found\n";
    }
};

int main(){
    List ll;
    ll.push_front(6); // 6
    ll.push_front(7); // 7 -> 6 
    ll.push_front(8); // 8 -> 7 -> 6
    ll.push_front(9); // 9 -> 8 -> 7 -> 6
    ll.push_front(10);// 10 -> 9 -> 8 -> 7 -> 6

    // ll.push_back(5); //10 -> 9 -> 8 -> 7 -> 6 -> 5 
    // ll.push_back(4); //10 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4 
    // ll.push_back(3); //10 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3
    // ll.push_back(2); //10 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 
    // ll.push_back(1); //10 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 

    // ll.pop_front();  // 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 
    // ll.pop_front();  // 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 
    // ll.pop_front();  // 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 
    // ll.pop_front();  // 6 -> 5 -> 4 -> 3 -> 2 -> 1

    // ll.pop_back(); //10 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2
    // ll.pop_back(); //10 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3
    // ll.pop_back(); //10 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4

    
    ll.push_in_middle(4,1); // 10 -> 4 -> 9 -> 8 -> 7 -> 6 -> NULL
    ll.push_in_middle(5,1); // 10 -> 5 -> 4 -> 9 -> 8 -> 7 -> 6 -> NULL

    ll.printLL();
    ll.search_in_LL(10);

    return 0;
}
