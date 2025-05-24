#include <iostream>
#include <vector>
#include <algorithm> // Included to use sort function
using namespace std;

// THIS IS THE BRUTE FORCE METHODE

// int majorityElement(vector<int> nums)
// {
//     int n = nums.size();
//     for (int val : nums)
//     {
//         int freq = 0;

//         for (int el : nums)
//         {
//             if (el == val)
//             {
//                 freq++;
//             }
//         }
//         if (freq > n / 2)
//         {
//             return val;
//         }
//     }
//     return -1;
// }

// vector<int> nums = {5, 3, 4, 4, 4, 4, 4, 5, 2};
// cout << majorityElement(nums);

           // OR

// int majorityElement(vector<int> nums)
// {

//     int n = nums.size(), ans = nums[0], freq = 1;
//     sort(nums.begin(), nums.end());
//     for (int i = 1; i < n; i++)
//     {

//         if (nums[i] == nums[i - 1])
//         {
//             freq++;
//         }
//         else
//         {
//             freq = 1;
//             ans = nums[i];
//         }
//         if (freq > n / 2)
//         {
//             return ans;
//         }
//     }
//     return -1;
// }
// vector<int> nums = {5, 3, 5, 4, 5, 4, 5, 5, 2};
// cout << majorityElement(nums);

           // OR (MOORE's VOTING ALGORITHM)

int majorityElement(vector<int> nums)
{

    int n = nums.size();
    int freq = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
        {
            ans = nums[i];
        }
        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
       
    }
     return ans;
}

int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums);

    return 0;
}