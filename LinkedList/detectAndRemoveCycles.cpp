//LeetCode Problem 

#include<iostream>
#include<algorithm>
using namespace std;

// To create ListNode for linked list
class ListNode{
public:
    int data;
    ListNode* next;

    ListNode(int val){
        data = val;
        next = NULL;
    }
};

// This is the list for every operation which we have to perform
class List{
    ListNode *head;
    ListNode *tail;

public:
    List(){
        head = NULL;
        tail = NULL;
    }  
    
    ListNode* headPtr(){
        ListNode* temp = head;
        return temp;
    }

    //Insert at the end (last) of the linked list   TC : O(1) due to tail ListNode else TC : O(n)
    void push_back(int val){
        ListNode* newListNode = new ListNode(val);
        
        if(head == NULL){
            head = tail = newListNode;
            return;
        }else{
            tail->next = newListNode;
            tail = newListNode;
        }
    }

    //Display the linked list     TC : O(n)
    void printLL(ListNode *head){
        ListNode* temp = head;
        while (temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

};

//This detect the cycle  (main code)
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
     
    while(fast != NULL  && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast){
            return true;
        }
        
    }

    return false;
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
    
    cout << hasCycle(ll.headPtr()) << endl;


    return 0;
}
