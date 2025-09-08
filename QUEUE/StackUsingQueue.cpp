// leetCode 225
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class MyStack {
queue<int> q1;
queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) { //O(n)
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        q1.push(x);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack myStack ;
    myStack.push(1);
    myStack.push(2);
    cout << myStack.top() << endl; // return 2
    cout << myStack.pop() << endl; // return 2
    cout << myStack.empty() << endl; // return False
   


    return 0;
}