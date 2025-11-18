#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void slidingWindowMax(vector<int> nums, int k) {
    priority_queue <pair<int, int>> pq; // (arr[i], i)

    // 1st window
    for(int i=0; i<k; i++) {
        pq.push(make_pair(nums[i], i));
    }

    cout << "Output : " << pq.top().first << " ";

    for(int i=k; i<nums.size(); i++) {
        while(!pq.empty() && pq.top().second <= (i-k)) {  // outside window
            pq.pop();   
        }

        pq.push(make_pair(nums[i], i));
        cout << pq.top().first << " ";
    }

    cout << endl;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    slidingWindowMax(nums ,k);

    return 0;
}