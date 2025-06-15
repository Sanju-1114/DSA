#include <iostream>
#include <vector>
#include<list>
#include<deque>       
using namespace std;     
                        
int main(){
    deque<int> d = {1,2,3};
    
    for(int val : d){
    cout << val << " ";
   }

    cout << endl;

    return 0;
}

// DEQUE --> Double ended queue  --> like dynamic arrays -> random access possible
   // Dequeue --> used to pop the data from any que
// DEQUE functions
  // push_front()
  // push_back()
  // pop_front()
  // pop_back()
  // emplace_front()
  // emplace_back()
  // size
  // erase
  // clear
  // begin
  // end
  // rbegin
  // rend
  // insert
  // front
  // back
