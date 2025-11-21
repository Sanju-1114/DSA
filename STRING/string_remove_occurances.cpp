//Remove all occurrences from string
// => str.find( substring/part)     --> it returns the starting index of the part of the string which given in it or in this braces
// => str.erase( start ,end)  --> start-> is the starting point and     
                              //  end-> is the length of the string   

#include<iostream>

using namespace std;

string removeOccurrences(string str , string part){
   while((str.find(part)<str.length()) && str.length()>0){
     str.erase(str.find(part),part.length());
   }
     return str;
}
int main(){
    string str = "daabcbaabcbc";
    string part = "abc";
    
    cout <<  removeOccurrences(str , part) << endl;

    return 0;
}