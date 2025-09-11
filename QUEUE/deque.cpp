#include <iostream>
#include <vector>
#include<deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);  // 1, 2, 3

    dq.push_front(4); //4, 1, 2, 3
    
    dq.pop_back();  //4, 1, 2
    
    cout << dq.front() << " " << dq.back() << endl;

    return 0;
}