//LeetCode Problem 25

#include<iostream>
#include<algorithm>
using namespace std;


//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    int count = 0;
    // check if k node exist
    while(count < k){
        if(temp == NULL){
            return;
        }
        temp = temp->next;
        count++;
    }

    // recursively call for the rest of the LL
    ListNode* prevNode = reverseKGroup(temp , k);

    // reverse current group
    temp = head ; count = 0;
    while (count < k){
        ListNode* next = temp->next;
        temp->next = prevNode;

        prevNode = temp;
        temp = next;

        count++;
    }
        
    return prevNode;
}





// Function to display the linked list
// void display(Node* head) {
//     Node* temp = head;
//     while (temp) {
//         cout << temp->data << " -> ";
//         temp = temp->next;
//     }
//     cout << "NULL" << endl;
// }


int main(){
   
   

    return 0;
}
