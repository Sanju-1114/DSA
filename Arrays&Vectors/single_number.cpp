#include<iostream>
#include<vector>
using namespace std;

  int singleNumber(vector<int>& nums) {
      int ans=0;
        for(int val:nums){
           ans^=val;
        }
        return ans;
    }

int main(){
    vector<int>nums={1,2,3,2,1};
    cout<<"Single number = "<<singleNumber(nums)<<endl;

    return 0;
}