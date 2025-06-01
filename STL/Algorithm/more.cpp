#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> nums = {1,2,3,4,5};
    
    cout << *(max_element(nums.begin(),nums.end())) << endl; //--> it returns the iterator of the max(biggest) element so we need to de-reference
    
    cout << *(min_element(nums.begin(),nums.end())) << endl; //-->it returns the iterator of the min(smallest) element so we need to de-reference
    
    cout << binary_search(nums.begin(),nums.end(),4)<< endl; //-->binary_search(starting , ending , target) --> return the boolean (true or false)

 // Count Set Bits
    int n = 15;
    cout << __builtin_popcount(n) << endl;
    cout << __builtin_popcountl(n) << endl;
    cout << __builtin_popcountll(n) << endl;
    
    // Count Set Bits
      // -> __builtin_popcount()       --> it ruturns binary me kitne bit jagah lega wo number  --> for int
      // -> __builtin_popcountl()      --> for long int
      // -> __builtin_popcountll()     --> for long long int

    // for(int val : nums){
    //     cout << val << " ";
    // }
    // cout << endl;


   

    return 0;
}