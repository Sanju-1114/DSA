#include <iostream>
#include<vector>
#include<list>     
using namespace std;     
                        
int main(){
    // list<int> l = {1,2,3,4,5};
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(0);
    l.push_front(-1);
    l.push_front(-2);

    l.pop_back();            
    l.pop_front();

   for(int val : l){
    cout << val << " ";
   }

    cout << endl;

    return 0;
}


---

// list --> implemented like a Doubly Linked List --> so we can insert and delete from both side --> front and back
   // --> random access not possible
// LIST functions
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