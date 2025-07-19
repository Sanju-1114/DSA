//LeetCode Problem 21

#include<iostream>
#include<algorithm>
using namespace std;

// To create node for linked list
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

    //Insert at the end (last) of the linked list   TC : O(1) due to tail node else TC : O(n)
    void push_back(int val){
        ListNode* newNode = new ListNode(val);
        
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            tail->next = newNode;
            tail = newNode;
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

ListNode* mergeTwoLists(ListNode* head1 ,ListNode* head2 ){   // TC : O(m+n)
    if(head1 == NULL || head2 == NULL){
        return head1 == NULL ? head2 : head1;
    }

    // case1
    if(head1->data <= head2->data){
        head1->next = mergeTwoLists(head1->next , head2);
        return head1;
    }else{ //case2
        head2->next = mergeTwoLists( head1 , head2->next);
        return head2;
    }
}

int main(){
    List list1;
    List list2;
  
    list1.push_back(1); 
    list1.push_back(3);
    list1.push_back(5);

    list2.push_back(2); 
    list2.push_back(3);
    list2.push_back(6);
    
    list1.printLL(list1.headPtr());
    list1.printLL(list2.headPtr());
   
    ListNode* newListHead =  mergeTwoLists(list1.headPtr() , list2.headPtr()); //returns new node of mergedList

    list1.printLL(newListHead);

    return 0;
}
