#include <iostream>
#include <vector>
#include <list>
#include <deque> 
#include <stack>   
#include<queue>   
using namespace std;     
                        
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
     
    cout  << endl;
    return 0;
}
// QUEUE -->  FIFO data structure
  // push    -->  to push data here --> q.push(`any data here`)            --> q.push(1)
  // emplace -->  same as push                                             --> q.emplace(2)
  // front   -->  to check which data(element) is in front                 --> q.front()
  // pop     -->  pop or delete the element from the top                   --> q.pop()
  // size    -->  display the correct or let say current size of the stack --> q.size()
  // empty   -->  used to track that stack is empty or not                 --> q.empty()
  // swap    -->  swap the one stack data to other   --> s1 = {1,2,3} and s2={} --> s2.swap(s1) --> now s1 is empty and s2 = {1,2,3}