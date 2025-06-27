// LeetCode problem 46
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;                                           //OR
                            // TC : O(n! * n)        SC: O(n!+n) ==>  SC: O(n!)
void getPerm(vector<int> &nums , int idx , vector<vector<int>> &ans){
   if(idx == nums.size()){
      ans.push_back({nums});
      return;
   }

   for(int i = idx ; i<nums.size() ; i++){
      swap(nums[idx] , nums[i]); // idx place ==> ith element choice
      getPerm(nums , idx+1 , ans);

      swap(nums[idx] , nums[i]); // Backtracking step

   }
}  
vector<vector<int>> permutation(vector<int> &nums){
    vector<vector<int>> ans;

    getPerm(nums , 0 , ans);

    return ans;
}

int main(){
    vector<int> nums = {1,2,3};
    
    for(vector<int> val : permutation(nums)){
        for(int per : val){
           cout << per << " ";
        }
        cout << endl;
     }
    
    return 0;
}