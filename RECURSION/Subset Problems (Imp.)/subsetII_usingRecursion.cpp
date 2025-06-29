// LeetCode problem 90
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;     
                              // TC : O(2^n *n) 
void getAllSubsets(vector<int> &nums , vector<int> &ans , int i , vector<vector<int>> &allSubsets){     
     if(i == nums.size()){
        allSubsets.push_back({ans});  //push all values in the anas array
        return;
     }  

     // Include
     ans.push_back(nums[i]);
     getAllSubsets(nums,ans,i+1 ,allSubsets);
     
     ans.pop_back(); // Backtrack
     //Exclude
     int idx = i+1;
     while (idx < nums.size() && nums[idx] == nums[idx-1]){
          idx++;
        }
        
        getAllSubsets(nums , ans , idx, allSubsets);

}

vector<vector<int>> subsetsWithDup(vector<int> &nums){
    sort(nums.begin() , nums.end());
    vector<vector<int>> allSubsets;
    vector<int> ans;
    getAllSubsets(nums , ans , 0 , allSubsets);

    return allSubsets; 
}


int main()
{
    vector<int> nums = {1,2,2};
    vector<int>ans;   // Store subsetsWithDup

    for(vector<int> val : subsetsWithDup(nums)){
       for(int ins : val){
          cout << ins << " ";
       }
       cout << endl;
    }
   

    return 0;
}