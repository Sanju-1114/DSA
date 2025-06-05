#include <iostream>
#include <vector>
#include <list>
#include <deque> 
#include <stack>      
using namespace std;     
                        
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.emplace(4);
    
    stack<int> s2;
    s2.swap(s);

    cout <<  s.size()  << endl;
    cout <<  s2.size()  << endl;

    // while (!s.empty()){
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    
    cout  << endl;

    return 0;
}

//STACK --> LIFO data structure
  // push    -->  to push data here --> s.push(`any data here`)            --> s.push(1)
  // emplace -->  same as push                                             --> s.emplace(2)
  // top     -->  to check which data(element) is at top                   --> s.top()
  // pop     -->  pop or delete the element from the top                   --> s.pop()
  // size    -->  display the correct or let say current size of the stack --> s.size()
  // empty   -->  used to track that stack is empty or not                 --> s.empty()
  // swap    -->  swap the one stack data to other   --> s1 = {1,2,3} and s2={} --> s2.swap(s1) --> now s1 is empty and s2 = {1,2,3}