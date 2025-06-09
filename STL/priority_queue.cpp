#include <iostream>
#include <vector>
#include <list>
#include <deque> 
#include <stack>   
#include<queue>   
using namespace std;     
                        
int main(){
    priority_queue<int> q;
    // priority_queue<int , vector<int>, greater<int>> q;   --> used to print in reverse order
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
     
    cout  << endl;
    return 0;
}
// PRIORITY_QUEUE --> it always store the highest priority value at top --> in this case (4 -> 3 -> 2 -> 1)
  // push    -->  to push data here --> q.push(`any data here`)            --> q.push(1)
  // emplace -->  same as push                                             --> q.emplace(2)
  // top     -->  to check which data(element) is at top                   --> q.top()
  // pop     -->  pop or delete the element from the top                   --> q.pop()
  // size    -->  display the correct or let say current size of the stack --> q.size()
  // empty   -->  used to track that stack is empty or not                 --> q.empty()