#include<iostream>
#include<vector>
using namespace std;                           // THIS CODE ONLY FOR SORTED ARRAY 

// vector<int>twoSum(vector<int>pairSum,int target){
//     vector<int>ans;
//    for(int i=0;i<pairSum.size();i++){
//       for(int j=i+1;j<pairSum.size();j++){
//         if(pairSum[i]+pairSum[j]==target){
//             ans.push_back(i);
//             ans.push_back(j);                                       calculate pair sum and return their index number
//             return ans;
//         }
//       }
//       return ans;
//    }
// }
//     int target=9;
//     vector<int>pairSum={2,7,11,15};
    
//     vector<int>ans = twoSum(pairSum,target);
//     cout<<ans[0]<<","<<ans[1]<<endl;  


vector<int>pairSum(vector<int>nums,int target){
    vector<int>ans;
    int n=nums.size();
    int i=0,j=n-1;
    while(i<j){
      int pairSum=nums[i]+nums[j];
      if(pairSum>target){
        j--;                                            
      }                                                  
      else if(pairSum<target){
        i++;
      }
      else{
        ans.push_back(i);
        ans.push_back(j);
        return ans;
      }
    }
    return ans;
}



int main(){
     int target=26;
     vector<int>nums={2,7,11,15};
     vector<int>ans = pairSum(nums,target);
     cout<<ans[0]<<","<<ans[1]<<endl;

    return 0;
}