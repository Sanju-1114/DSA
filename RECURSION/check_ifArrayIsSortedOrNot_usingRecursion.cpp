#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int> &nums , int n){             // TC : O(n)               SC:O(n)
   if(n==0 || n==1) return true; 
   return  nums[n-1] >= nums[n-2] && isSorted(nums , n-1);
}

int main(){
   vector<int> nums = {1,2,3,4,5};
   int n= nums.size();
  
    cout << isSorted(nums , n) << endl;

    return 0;
}