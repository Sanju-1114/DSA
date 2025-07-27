#include <iostream>
#include<vector> //to creat Stack using vector
#include<list>  //to creat Stack using Linked List
#include<stack>  // implementation of stack through C++ STL stack
using namespace std;

// //Stack using Linked List
// class Stack{
//     list<int> ll;
// public:
//     // Insert the data in stack
//     void push(int val){
//         ll.push_front(val);
//     }    

//     // Delete the data from the Stack
//     void pop(){
//         ll.pop_front();
//     }

//     // return the value at the top of the stack
//     int top(){
//         return ll.front();
//     }

//     bool empty(){
//         return ll.size() == 0;
//     }

// };

//Stack using vector
// class Stack{
//     vector<int> ll;
// public:
//     // Insert the data in stack
//     void push(int val){
//         ll.push_back(val);
//     }    

//     // Delete the data from the Stack
//     void pop(){
//         ll.pop_back();
//     }

//     // return the value at the top of the stack
//     int top(){
//         return ll[ll.size()-1];
//     }

//     bool empty(){
//         return ll.size() == 0;
//     }

// };

int main() {

    // Stack s;   //for stack using vector and linked list

    stack <int> s; // using C++ STL

    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}