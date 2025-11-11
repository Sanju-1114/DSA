// Problem 1 on leetCode
// Hashing means when we use MAP and SETS in programming
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// int twoSum(vector<int>& nums , int target){
//                                           // First methode - Brute Force Approach  O(n^2)
//     int n = nums.size();  
//     for(int i=0 ; i<n ; i++){
//         int first = nums[i];
//         for(int j = i+1 ; j < n ; j++){
//             int second = nums[j];

//             int sum = first + second ;

//             if(first + second == target){
//                 return true;
//             }
//         }
//     }

// }

// vector<int> twoSum(vector<int>& nums , int target){
//                                                 // Second Methode - Better approach    O(nlogn)
//     int n = nums.size();
//     vector<int> ans;
//     // Sort the array/vector
//     sort(nums.begin() , nums.end());
//     int smallest = 0 , largest = n-1;
//     while(smallest <= largest){
//         int sum = nums[smallest] + nums[largest];
//         if(sum == target){
//             ans.push_back(smallest);
//             ans.push_back(largest);
//             break;
//         }else if(sum > target){
//             largest--;
//         }else{
//             smallest++;
//         }
//     }
//      return ans;                            // it returns the indexes after sorting OR sorted index
// }


vector<int> twoSum(vector<int>& nums , int target){
                                                        // Third Methode - Optimized approach    O(n)
    unordered_map <int,int>m;
    int n = nums.size();
    vector<int> ans;
    for(int i=0 ; i < n ; i++){
        int first = nums[i];
        int second = target - first;

        if(m.find(second) != m.end()){
           ans.push_back(i);
           ans.push_back(m[second]);
           break;
        }
        
        m[first] = i;
    }
    return ans;
}



int main(){
 
    vector<int> vec = {5,2,11,7,15};
    int target = 9;
    
    for(int idx : twoSum(vec , target)){
    cout << idx << " ";
    }
    cout << endl;
    return 0;
}