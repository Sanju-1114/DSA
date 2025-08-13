// LeetCode 
#include <iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

vector<int> previousSmallerElement(vector<int> &nums){
    stack<int> s;
    vector<int> ans(nums.size() , 0);

    for(int i = 0; i < nums.size() ; i++){
        while(s.size() > 0 && s.top() >= nums[i]){   // removing invalid elements (which never be ans)
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        }else{
            ans[i] = s.top();
        }

        s.push(nums[i]);
    }

    return ans;
}

int main(){
   vector<int> nums1 = {3, 1, 0, 8, 6};
   
    for(int val : previousSmallerElement(nums1)){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}