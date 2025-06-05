#include <iostream>
#include <vector>  
#include <map>
#include<unordered_map>
#include<set>
#include<unordered_set>
using namespace std;     
                        
int main(){
    unordered_set<int>s;
    s.emplace(1);
    s.emplace(2);
    s.emplace(3);

    s.emplace(4);
    s.emplace(4);         // It ignore the dublicate data and store it only once   
    s.emplace(4);

    cout << "Size of the set : " << s.size() << endl; 
    
    for(auto val : s){
        cout << val << " ";
    }
   
   
    cout  << endl;
    return 0;
} 

// UNORDERED_SET -->  store the data in any order  ==> unordered
  // insert    -->  used to insert new data                                --> s.insert(value)                
  // emplace -->  same as push                                             --> s.emplace(value)
  // count   --> returns the number of keys of any instance im map       
  // erase
  // find
  // size    -->  display the correct or let say current size of the stack --> s.size()
  // empty   -->  used to track that stack is empty or not                 --> s.empty()
