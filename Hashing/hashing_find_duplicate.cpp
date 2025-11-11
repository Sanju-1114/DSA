// Problem 287 on leetCode
// Hashing means when we use MAP and SETS in programming
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// int findDuplicate(vector<int>& nums){    // Time complexity -> O(n)
//     unordered_set<int> s;                // Space complexity -> O(n)
    
//     for(int val : nums){
//         if(s.find(val) != s.end()){
//             return val;
//         }
//         s.insert(val);
//     }
//    return -1;
// }


// Slow - fast pointer approach
int findDuplicate(vector<int>& nums){    // Time complexity -> O(n)  // Space complexity -> O(1)
    int slow = nums[0] , fast = nums[0] ;
    do{                                 
        slow = nums[slow];             // it means slow += 1
        fast = nums[nums[fast]];      // it means fast += 2
    }while(slow != fast);
    
    slow = nums[0];
    while(slow != fast){
        slow = nums[slow];     // it means slow += 1
        fast = nums[fast];     // it means fast += 1
    }
   return slow;                  
}

int main(){
 
    vector<int> vec = {1,3,2,3,4};
    
    cout << findDuplicate(vec) << endl;
    
    return 0;
}   