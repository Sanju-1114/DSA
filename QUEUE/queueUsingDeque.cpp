#include <iostream>
#include <deque>
using namespace std;

class Queue{
deque<int> dq;

public:
    Queue(){

    }

    void push(int val){
        dq.push_back(val);
    }

    void pop(){
        dq.pop_front();
    }

    int front(){
        return dq.front();
    }

    bool empty(){
        return dq.empty();
    }
};

int main() {
    Queue q;
    
    for(int i=1; i<=5 ; i++){
        q.push(i);
    }

    for(int i=1; i<=5 ; i++){
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;



    return 0;
}