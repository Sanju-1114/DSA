#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool comparator(pair<int,int> p1 , pair<int,int>p2){
      if(p1.second < p2.second)  return true;
      if(p1.second > p2.second)  return false;

      if(p1.first < p2.first)    return true;
      else  return false;
}

int main()
{
    // int arr[] = {1,5,3,6,7,3,0};
    // int n = 7  ; // nums.size();

    // sort(arr , arr+n);                    --> sort in ascending order (default)
    // sort(arr , arr+n , greater<int>());   --> sort in descending order

    // for (int i = 0; i < n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;


    // vector<int> nums = {1,5,3,6,7,3,0};

    // sort(nums.begin() , nums.end());
    // // sort(nums.begin() , nums.end() , greater<int>());

    // for(int val : nums){
    //     cout << val << " ";
    // }
    // cout << endl;


    vector<pair<int,int>> nums = {{3,1} , {2,1} , {7,1} , {5,2}};

    sort(nums.begin() , nums.end());
    // sort(nums.begin() , nums.end() , greater<int>());     --> default comparator
    // sort(nums.begin() , nums.end() , comparator);         --> custom comparator
    for(pair<int,int> p : nums){
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;

    return 0;
}