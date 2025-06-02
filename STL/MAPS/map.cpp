#include <iostream>
#include <vector>  
#include <map>
using namespace std;     
                        
int main(){
    map<string,int>m;
    m["Sanju"] = 5;
    m["Vikash"] = 6;
    m["Kumar"] = 7;

    m.insert({"Patel" , 9});
    m.emplace("SanjuBhai" , 10);
    m.erase("Kumar");

    for(auto p:m){
        cout << p.first << " " << p.second << endl;
    }
    m.find("Sanju") != m.end() ? cout << "Found" : cout << "Not found"; 

    cout  << endl;
    return 0;
} 
//  m[key] = value   (way to insert)
// MAP -->  they print in ascending order as per key   --> sorted in ascending order
  // insert    -->  used to insert new data                                --> m.insert({"key", value})                
  // emplace -->  same as push                                             --> m.emplace("key" , value)
  // count   --> returns the number of keys of any instance im map         --> m.count("Vikash") --> output = 1 
  // erase
  // find
  // size    -->  display the correct or let say current size of the stack --> m.size()
  // empty   -->  used to track that stack is empty or not                 --> m.empty()