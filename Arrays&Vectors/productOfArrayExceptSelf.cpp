#include <iostream>
#include <vector>
using namespace std;

// vector<int> productExceptSelf(vector<int> &nums)
// {

//     int n = nums.size();
//     vector<int> result(n, 1);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {                                                              //This is the brute force method approach
//             if (i != j)
//                 result[i] *= nums[j];
//         }
//     }
//     return result;
// }
//  vector<int> nums = {1, 2, 3, 4};
//     vector<int>result = productExceptSelf(nums);

//     for(int val:result){
//         cout<<val<<" ";
//     }



// vector<int> productExceptSelf(vector<int> &nums)                       //optimised but time and space complexity both are O(n) but we need
// {                                                                      // space complexity of O(1)
//     int n = nums.size();
//     vector<int> ans(n, 1);
//     vector<int> prefix(n, 1);
//     vector<int> suffix(n, 1);

//     for (int i = 1; i < n; i++)
//     {
//         prefix[i] = prefix[i - 1] * nums[i - 1];
//     }

//     for (int i = n-2; i>=0; i--)
//     {
//         suffix[i] = suffix[i + 1] * nums[i + 1];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         ans[i] =    prefix[i]* suffix[i] ;
//     }
//    return ans;
// }


vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);
    
    int prefix=1;
    int suffix=1;

    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i-1] * nums[i - 1];
    }

    for (int i = n-2; i>=0; i--)
    {
         
        suffix*= nums[i + 1];
        ans[i]*=suffix;
    }
   
   return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);

    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}