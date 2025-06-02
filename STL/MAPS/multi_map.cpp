#include <iostream>
#include <vector>  
#include <map>
using namespace std;     
                        
int main(){
    multimap<string,int>m;
    // m["Sanju"] = 5;
    // m["Vikash"] = 6;     Not allowed in multimap
    // m["Kumar"] = 7;
    m.emplace("SanjuBhai" , 10);
    m.emplace("Sanju" , 12);
    m.emplace("Vikash" , 14);
    m.emplace("Kumar" , 150);
    m.emplace("Kumar" , 150);          // we can also create multiple times with same value
    m.emplace("Kumar" , 150);
    
    // m.erase("Kumar");               // erase all the data matching with this
    m.erase(m.find("Kumar"));          // delete only one occurrance

    for(auto p:m){
        cout << p.first << " " << p.second << endl;
    }

    m.find("Sanju") != m.end() ? cout << "Found" : cout << "Not found"; 

    cout  << endl;
    return 0;
} 

// MAP -->  they print in ascending order as per key   --> sorted in ascending order
  // insert    -->  used to insert new data                                --> m.insert({"key", value})                
  // emplace -->  same as push                                             --> m.emplace("key" , value)
  // count   --> returns the number of keys of any instance im map         --> m.count("Vikash") --> output = 1 
  // erase
  // find
  // size    -->  display the correct or let say current size of the stack --> m.size()
  // empty   -->  used to track that stack is empty or not                 --> m.empty()