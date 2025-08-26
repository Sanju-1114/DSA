// LeetCode 42 - Hard level Problem
#include <iostream>
#include<vector>
#include<stack>
using namespace std;

// Optimised approach || 2 pointer  Approach
int trap(vector<int>& height){
    int n = height.size();
    int ans = 0;
    
    int l = 0;
    int r = n-1;

    int lmax = 0;
    int rmax = 0;

    while(l < r){
        lmax = max(lmax , height[l]);
        rmax = max(rmax , height[r]);

        if(lmax < rmax){
            ans += lmax - height[l];
            l++;
        } else{
            ans += rmax - height[r];
            r--;
        }
    }
    return ans;
}

// // Better approach || prefixArray Approach
// int trap(vector<int>& height){
//     int n = height.size();
//     int ans = 0;
//     vector<int> lmax(n, 0);
//     vector<int> rmax(n, 0);

//     lmax[0] = height[0];
//     rmax[n-1] = height[n-1];

//     // left boundary for every element
//     for(int i=1; i<n ; i++){
//         lmax[i] = max(lmax[i-1] , height[i]);
//     }

//     // right boundary for every element
//     for(int i=n-2; i>=0 ; i--){
//         rmax[i] = max(rmax[i+1] , height[i]);
//     }

//     for(int i=0 ; i<n ; i++){
//         ans += min(lmax[i] , rmax[i]) - height[i];
//     }

//     return ans;
// }

int main() {

    vector<int> height = {4,2,0,3,2,5};

    cout << "Trapped water : " << trap(height) << endl;

    return 0;
}