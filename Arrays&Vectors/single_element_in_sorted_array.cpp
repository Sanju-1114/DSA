#include <iostream>
#include <vector>
using namespace std;

 int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        int st = 0;
        int end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (mid == 0 && nums[0] != nums[1])
                return nums[mid];
            if (mid == n - 1 && nums[n - 1] != nums[n - 2])
                return nums[mid];
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
                return nums[mid];

            if (mid % 2 == 0) {

                if (nums[mid - 1] == nums[mid]) {
                    end = mid - 1; // left
                } else {
                    st = mid + 1; // right
                }
            }

            else {

                if (nums[mid - 1] == nums[mid]) {
                    st = mid + 1; // right
                } else {
                    end = mid - 1; // left
                }
            }
        }
        return -1;
    }

int main()
{
    vector<int> nums = {1, 1, 4, 4, 5, 8, 8};
    int ans = singleNonDuplicate(nums);
    cout << "Single element is : " << ans << endl;

    return 0;
}