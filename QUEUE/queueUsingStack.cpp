// leetCode 232
#include <iostream>
#include <vector>
#include<stack>
using namespace std;

class MyQueue {
stack<int> s1;    
stack<int> s2;    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() { //O(1)    Front
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q ;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.peek() << endl; 
    cout << q.pop() << endl; 
    cout << q.empty() << endl; 
   

    return 0;
}