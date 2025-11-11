
// Hashing means when we use MAP and SETS in programming
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

           // Brute Force Approach             TC:O(n^2)     SC : O(1) 
// int subarraySum(vector<int> &nums, int k){
//     int n = nums.size();
//     int count = 0;
//     for (int i = 0; i < n; i++){
//         int sum = 0;
//         for (int j = i; j < n; j++){
//             sum += nums[j];
//             if (sum == k)
//                 count++;
//         }
//     }
//     return count;
// }

//Optimal code                              TC:O(n)     SC : O(n) 
int subarraySum(vector<int> &nums, int k){
    int n = nums.size();
    int count = 0;
    vector<int> prefixSum(n,0);

    prefixSum[0] = nums[0];           // store the sum of all the previous values of array
    for (int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    
    unordered_map<int,int> m;     // Store preix Sum with the frequency of the element
    for (int j = 0; j < n; j++){
        if (prefixSum[j] == k) count++;
        
        int val = prefixSum[j] - k;          // find the startigIndex-1 of the subarray
        if (m.find(val) != m.end()){         // Check the value exist in map or not
            count += m[val];                 // if yes the count increased by 1
        }
        if (m.find(prefixSum[j]) == m.end()){         // if not then add it to the map
            m[prefixSum[j]] = 0;             // at starting the frequncy of every element is 0

        }
        m[prefixSum[j]]++;                   //  then increase the frequency of the elements
    }
    
    return count;                      // return the count (how many subarray exist whose sum is equal to k)
}


int main()
{

    vector<int> vec = {9,4,20,3,10,5};
    int k = 33;
    cout << subarraySum(vec , k) << endl ;

    return 0;
}