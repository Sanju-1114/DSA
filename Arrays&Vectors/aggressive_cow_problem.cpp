#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &nums, int n, int c, int minAllowedDist) // O(n)
{
    int cows = 1, lastStallPos = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] - lastStallPos >= minAllowedDist)
        {
            cows++;
            lastStallPos = nums[i];
        }
        if (cows == c)
        {
            return true;
        }
    }
    return false;
}

int getDistance(vector<int> &nums, int n, int c) // O(logn *n)
{
    sort(nums.begin(), nums.end()); // sort the array

    int st = 1, end = nums[n - 1] - nums[0], ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isPossible(nums, n, c, mid))
        { // right
            ans = mid;
            st = mid + 1;
        }
        else
        { // left
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{

    vector<int> nums = {1, 2, 8, 4, 9};
    int n = 5, c = 3;

    int ans = getDistance(nums, n, c);
    cout << "Minimum distance = " << ans << endl;

    return 0;
}