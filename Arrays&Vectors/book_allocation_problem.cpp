#include<iostream>
#include <vector>
using namespace std;


bool isValid(vector<int> &nums, int n, int m, int maxAllowedPages)         //O(n)
{
    int stu = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > maxAllowedPages)
            return false;
        if (pages + nums[i] <= maxAllowedPages)
        {
            pages += nums[i];
        }
        else
        {
            stu++;
            pages = nums[i];
        }
    }
    if (stu <= m)
        return true;
    else
        return false;
}

int allocateBooks(vector<int> &nums, int n, int m)       // O(logn *n)
{   if(m>n) return -1;

    int sum = 0;
    for (int i = 0; i < n; i++)        //O(n)
    {
        sum += nums[i];
    }

    int  ans = -1;
    int st = 0, end = sum;   //range of possible ans

    while (st <= end)                    // O(logn *n)
    {
        int mid = st + (end - st) / 2;

        if (isValid(nums,n,m, mid))
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

    vector<int> nums = {15,17,20};
    int n = 3, m = 2;

    int ans = allocateBooks(nums, n, m);
    cout << "Answer = " << ans << endl;

    return 0;
}