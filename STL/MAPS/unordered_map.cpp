#include <iostream>
#include <vector>  
#include <map>
#include<unordered_map>
using namespace std;     
                        
int main(){
    unordered_map<string,int>m;
    m.emplace("SanjuBhai" , 10);
    m.emplace("Sanju" , 12);
    m.emplace("Vikash" , 14);

    m.emplace("Kumar" , 150);
    m.emplace("Kumar" , 150);          // we can't dublicate data
    m.emplace("Kumar" , 150);
    

    for(auto p:m){
        cout << p.first << " " << p.second << endl;
    }

    m.find("Sanju") != m.end() ? cout << "Found" : cout << "Not found"; 

    cout  << endl;
    return 0;
} 

// UNORDERED_MAP -->  store the data in random order
  // insert    -->  used to insert new data                                --> m.insert({"key", value})                
  // emplace -->  same as push                                             --> m.emplace("key" , value)
  // count   --> returns the number of keys of any instance im map         --> m.count("Vikash") --> output = 1 
  // erase
  // find
  // size    -->  display the correct or let say current size of the stack --> m.size()
  // empty   -->  used to track that stack is empty or not                 --> m.empty()