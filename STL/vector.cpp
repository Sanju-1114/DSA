#include <iostream>
#include <vector>       
using namespace std;     
                        
int main(){

    vector<int> vec = {1,2,3,4,5};  
    // vector<int>::iterator it;
    // vector<int>::reverse_iterator j;   instead of this write auto in front of iterator

    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *(it) << " ";
    }
    
    cout << endl;
    
    for (auto j = vec.rbegin(); j != vec.rend(); j++){
        cout << *(j) << " ";
    }

    cout << endl;

    return 0;
}

// VECTOR --> functions or important concepts

   // vec.size() --> used to find the size of the vector
   // vec.capacity()--> this return the actual size which taken by vector in memory (due to push_back() function)

   // vec.push_back() -->used to push the data in the vector
   // vec.pop_back() -->used to pop the data from the end of the vector
   // vec.emplace_back() -->used to push the data in vector

   // vector<int> vec(3,10); // --> vector of size 3 and each value is 10 
   // vector<int> vec2(vec1);   // --> initilize vec2 same values of vec1

   // at() or []  --> used to access or print the data mostly we use [] like array.

   // front and back --> to get data from startin we use front and when we want data from last we use back.

   // erase->vec.earse(starting idx , ending idx[optional])->used to erase the more then one element or any one index value
   //                                ending idx value is not deleted by thhis function --> [start , end)    
   // insert -> vec.insert(pos or idx , val) --> insert the data at any place or position
   // clear -> vec.clear() --> clear whole vector
   // empty -> vec.empty() --> to check vector is empty or not

   // vec.begin() --> return the starting idx of the vector
   // vec.end()   --> return the ending+1  idx of the vector
   // vec.rbegin() --> return the ending idx of the vector
   // vec.rend()   --> return the starting-1  idx of the vector

