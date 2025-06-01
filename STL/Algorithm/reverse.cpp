#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> nums = {1,2,3,4,5};
    
    reverse(nums.begin() , nums.end());           // --> reverse the vector , array , etc.
    // reverse(nums.begin()+1 , nums.begin()+3);      --> to reverse the specific range

    for(int val : nums){
        cout << val << " ";
    }
    cout << endl;


   

    return 0;
}