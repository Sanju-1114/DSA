#include<iostream>
#include <vector>
using namespace std;


bool isPossible(vector<int> &nums, int n, int m, int maxAllowedTime)         //O(n)
{
    int painter = 1, time = 0;
    for (int i = 0; i < n; i++)
    {
       
        if (time + nums[i] <= maxAllowedTime)
        {
           time += nums[i];
        }
        else
        {
            painter ++;
            time = nums[i];
        }
    }
    // if (painter <= m)
    //     return true;
    // else
    //     return false;
    return painter <= m;
}

int minTimeToPaint(vector<int> &nums, int n, int m)       // O(logn *n)
{  

    int sum = 0 , maxValue = INT32_MIN;
    for (int i = 0; i < n; i++)        //O(n)
    {
        sum += nums[i];
        maxValue = max(maxValue,nums[i]);
    }

    int  ans = -1;
    int st = maxValue , end = sum;   //range of possible ans

    while (st <= end)                    // O(logn *n)
    {
        int mid = st + (end - st) / 2;

        if (isPossible(nums,n,m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
        
    }
   return ans;
}


int main()
{

    vector<int> nums = {40,30,10,20};
    int n = 4, m = 2;

    int ans = minTimeToPaint(nums, n, m);
    cout << "Minimum time required = " << ans << endl;

    return 0;
}