#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target, int left, int right)
{
    if (left <= right)
    {

        int middle = left + (right - left) / 2;

        if (nums[middle] < target)
        {
            return binarySearch(nums, target, middle + 1, right);
        }
        else if (nums[middle] > target)
        {
            return binarySearch(nums, target, left, middle - 1);
        }
        else
        {
            return middle;
        }
    }
    return -1;
}

int main()
{
    int target = 9;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int st = 0;
    int end = nums.size() - 1;

    int ans = binarySearch(nums, target, st, end);

    cout << "Index = " << ans << endl;

    return 0;
}