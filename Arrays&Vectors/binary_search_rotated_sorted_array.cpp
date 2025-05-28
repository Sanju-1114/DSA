#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (nums[middle] == target)
            return middle;

        if (nums[left] <= nums[middle])         //left sorted
        {   
            if (nums[left] <= target && target <= nums[middle])
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        else                                           //right sorted
        {
            if (nums[middle] <= target && target <= nums[right])
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
    }

    return -1;
}

int main()
{
    int target = 0;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int ans = binarySearch(nums, target);

    cout << "Index = " << ans << endl;

    return 0;
}