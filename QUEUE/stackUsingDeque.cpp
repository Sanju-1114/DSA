#include <iostream>
#include<deque>
using namespace std;

class Stack{
deque<int> dq;

public:
    Stack(){

    }

    void push(int val){
        dq.push_front(val);
    }

    void pop(){
        dq.pop_front();
    }

    int top(){
        return dq.front();
    }

    bool empty(){
        return dq.empty();
    }

};

int main() {

    Stack s;
    
    for(int i=1; i<=5 ; i++){
        s.push(i);
    }

    for(int i=1; i<=5 ; i++){
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
    return 0;
}