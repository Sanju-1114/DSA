// Problem 31 on leetCode
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
 //Step-1 :  find the pivot
    int pivot = -1 ,  n = nums.size();

    for(int i = n-2 ; i >= 0 ; i-- ){
           if(nums[i] < nums[i+1]){
              pivot = i;
              break;
           }
    }
    
    if(pivot == -1){
        // int i=0 , j = n-1;
        // while(i<=j){
        //     swap(nums[i++],nums[j--]);
        // }
        reverse(nums.begin() , nums.end());
         return;
    }

 // Step-2 : next larger element
    for(int i = n-1 ; i > pivot ; i--){
        if(nums[i] > nums[pivot]){
            swap(nums[i] , nums[pivot]);
            break;
        }
    }

 // Step-3 : reverse (pivot+1 to n-1)

    // reverse(nums.begin() + pivot+1 , nums.end());
    int i = pivot+1 , j = n-1;
    while(i<=j){
        swap(nums[i++] , nums[j--]);
    }
   
}

int main(){
    vector<int> nums = {1, 2, 3};

    nextPermutation(nums);
    
    for(int val : nums){
        cout << val << " ";
    }
    
    cout << endl;

    return 0;
}