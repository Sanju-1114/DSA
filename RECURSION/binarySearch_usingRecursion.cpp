// LeetCode problem 704
#include <iostream>
#include <vector>
using namespace std;      // TC : O(logn)    sC : O(logn)

// This perform binary search [known as Helper function]
int binarySearch(vector<int> &nums, int target, int left, int right){
    if (left <= right){

        int middle = left + (right - left) / 2;

        if (nums[middle] < target){
            return binarySearch(nums, target, middle + 1, right);
        }
        else if (nums[middle] > target){
            return binarySearch(nums, target, left, middle - 1);
        }
        else{
            return middle;
        }
    }
    return -1;
}

int search(vector<int> &nums, int target){
    int left = 0 , right = nums.size()-1;
     return binarySearch(nums , target , left , right);
}


int main()
{
    int target = 9;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int st = 0;
    int end = nums.size() - 1;

    int ans = search(nums, target);

    cout << "Index = " << ans << endl;

    return 0;
}