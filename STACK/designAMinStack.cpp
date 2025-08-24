// leetCode 155
#include <iostream>
#include<stack>
#include<deque>
using namespace std;

class MinStack {
public:
    stack<int> s;
    int minVal;
    MinStack() {
        
    }
    
   void push(int val) {
    if (s.empty()) {
        s.push(val);
        minVal = val;
    } else {
        if (val < minVal) {
            s.push((long long)2 * val - minVal);
            minVal = val;
        } else {
            s.push(val);
        }
      }
    }
    
    void pop() {
       if(s.top() < minVal){
        minVal = 2*minVal - s.top();
       }
       s.pop();
    }
    
    int top() {
        if(s.top() < minVal){
            return minVal;
        }else{
            return s.top();
        }
    }
    
    int getMin() { //O(1)
        return minVal;
    }
};

// class MinStack {
// public:

//     stack<pair<int, int>> s; // val , minVal
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(s.empty()){
//             s.push({val , val});
//         }else{
//             int minVal = min(val , s.top().second);
//             s.push({val , minVal});
//         }
//     }
    
//     void pop() {
//         s.pop();
//     }
    
//     int top() {
//         return s.top().first;
//     }
    
//     int getMin() {
//         return s.top().second;
//     }
// };

 int main() {
 MinStack minStack; // Create an instance of MinStack
    
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    cout << "Top element: " << minStack.top() << endl;       // Output: 7
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 3
    
    minStack.pop();
    
    cout << "Top element after pop: " << minStack.top() << endl;       // Output: 3
    cout << "Minimum element after pop: " << minStack.getMin() << endl; // Output: 3
  


    return 0;
}