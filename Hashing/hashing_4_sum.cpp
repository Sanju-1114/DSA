// Hashing means when we use MAP and SETS in programming
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include <set>
using namespace std;


vector<vector<int>> fourSum(vector<int>& nums){   // First methode - Two Pointer Approach
    int n = nums.size();
    vector<vector<int>> ans;   
    sort(nums.begin() , nums.end());

    for(int i=0 ; i<n ; i++){                      // i loop foe first number
        if(i>0 && nums[i] == nums[i-1]){        // to remove the duplicacy of ith number
            continue;
        }

       for(int j = i+1 ; j < n ;){               // j loop for second number
          int p = j+1 , q = n-1;                 // p third number & q fourth number
          while(p<q){
            long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];
            if(sum < 0){
               p++;
            }else if(sum > 0){
                q--;
            }else{
                ans.push_back({nums[i] , nums[j] , nums[p] , nums[q]});   // push pairs in loop
                p++ ; q--;

                while(p < q && nums[p] == nums[p-1]) p++;
            }
          }
        
          j++;                // which removed from the j loop
          if(j < n && nums[j] == nums[j-1]){      // avoid duplicacy
              j++;
        }
       }   
    }

    return ans;
}




int main(){
 
    vector<int> vec = {-2,-2,-1,-1,1,1,2,2};                       // In four sum we have to return the 4 values whose sum is 0
    
    for (auto i: fourSum(vec)) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}