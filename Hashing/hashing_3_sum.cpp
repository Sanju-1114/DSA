// Problem 15 on leetCode
// Hashing means when we use MAP and SETS in programming
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include <set>
using namespace std;

// vector<vector<int>> threeSum(vector<int>& nums){   // First methode - Brute Force Approach  
//     int n = nums.size();
//     vector<vector<int>> ans;  // To store and reteurn the answer (or Triplets)
//     set<vector<int>> s;    // set<uniqueTriplets>

//     for(int i=0 ; i<n ; i++){
//         for(int j = i+1 ; j < n ; j++){
//             for(int k = j+1 ; k<n ; k++){
//                 if(nums[i] + nums[j] + nums[k] == 0){
//                       vector<int> trip = {nums[i] , nums[j] , nums[k]};  // Store the triplets
//                       sort(trip.begin() , trip.end());

//                       if(s.find(trip) == s.end()){
//                          s.insert(trip);
//                          ans.push_back(trip);
//                     }
//                 }
//             }
//         }
//     }
//     return ans;
// }



// vector<vector<int>> threeSum(vector<int>& nums){   // Second methode - Approach with Hashing 
//     int n = nums.size();
//     set<vector<int>> uniqueTriplets;    // set<uniqueTriplets>

//     for(int i=0 ; i<n ; i++){
//         int target = -nums[i];
//         set<int> s;

//         for(int j = i+1 ; j < n ; j++){
//             int third = target - nums[j];

//             if(s.find(third) != s.end()){
//                 vector<int> trip = {nums[i] , nums[j] , third};
//                 sort(trip.begin() , trip.end());
//                 uniqueTriplets.insert(trip);
//             }

//             s.insert(nums[j]);
//         }
//     }
//     vector<vector<int>> ans = {uniqueTriplets.begin() , uniqueTriplets.end()};  // To store and reteurn the answer (or Triplets)
//     return ans;
// }



vector<vector<int>> threeSum(vector<int>& nums){   // Third methode - Two Pointer Approach
    int n = nums.size();
    vector<vector<int>> ans;   
    sort(nums.begin() , nums.end());

    for(int i=0 ; i<n ; i++){
        
        if(i>0 && nums[i] == nums[i-1]){
            continue;
        }

        int j = i+1 , k = n-1;
        while(j<k){
           int sum = nums[i] + nums[j] + nums[k];
           if(sum>0){
            k--;
           }else if(sum<0){
            j++;
           }else{
             ans.push_back({nums[i] , nums[j] , nums[k]});
             j++ ; k--;

             while( j < k && nums[j] == nums[j-1]){
                j++;
             }
           }
        }
    }
    return ans;
}




int main(){
 
    vector<int> vec = {-1,0,1,2,-1,-4};                       // In three sum we have to return the 3 values whose sum is 0
    
    for (auto i: threeSum(vec)) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}