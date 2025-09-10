// leetCode 239
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums , int k){ // O(n)
    deque<int> dq;
    vector<int> res;

    //1st window
    for(int i=0; i<k; i++){ //O(k)
        while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int i=k; i<nums.size(); i++){ //O(n-k)
        res.push_back(nums[dq.front()]);

        //remove elements which are not part of curr wind
        while(dq.size() > 0 && dq.front() <= i-k){
            dq.pop_front();
        }

        // remove smaller values
        while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }

        dq.push_back(i);
    }

    res.push_back(nums[dq.front()]);

    return res;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    for(int val : maxSlidingWindow(nums ,k)){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}