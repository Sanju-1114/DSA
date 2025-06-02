#include <iostream>
#include <vector>  
#include <map>
#include <unordered_map>
#include <set>
using namespace std;     
                        
int main(){
    set<int>s;
    s.emplace(1);
    s.emplace(2);
    s.emplace(3);

    s.emplace(4);
    s.emplace(4);        // It ignore the dublicate data and store it only once   
    s.emplace(4);

    cout << "Size of the set : " << s.size() << endl; 
    for(auto val : s){
        cout << val << " ";
    }
   
   
    cout  << endl;
    return 0;
} 

// SET -->  store the data in sorted order
  // insert    -->  used to insert new data                                --> s.insert(value)                
  // emplace -->  same as push                                             --> s.emplace(value)
  // count   --> returns the number of keys of any instance im map       
  // erase
  // find
  // size    -->  display the correct or let say current size of the stack --> s.size()
  // empty   -->  used to track that stack is empty or not                 --> s.empty()

  // JYADA USE NAHI HOTA HAI JANNA HAI TO C++ APNA COLLEGE STL VIDEO 1:03:29 SE 1:07:14 TAK DEKH SAKTE HAI
  // lower_bound                                                           --> s.lower_bound(`any data`) --> s.lower_bound(3) 
  // upper_bound                                                           --> s.upper_bound(`any data`) --> s.upper_bound(3) 