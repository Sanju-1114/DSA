// Problem 2965 on leetCode
// Hashing means when we use MAP and SETS in programming
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

vector<int> findMisingAndRepeatedValues(vector<vector<int>>& grid){
    vector<int> ans;
    unordered_set<int> s;      // Hashing concept
    int n = grid.size();
    int a,b;                   // a : repeating   ,  b : missing value

    int expectedSum = 0 , actualSum = 0;

     for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            actualSum += grid[i][j];

            if(s.find(grid[i][j]) != s.end()){
               a = grid[i][j];
               ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
     }
     expectedSum = (n*n) * (n*n + 1) / 2 ;
     b = expectedSum + a - actualSum;

     ans.push_back(b);

     return ans;
}

int main(){
 
    vector<vector<int>> vec = {{1,2,3} , {4,9,6} ,{7,8,9}};
    
    for(int val : findMisingAndRepeatedValues(vec)){
        cout << val << " ";                              // first : repeating   ,  second : missing value
    }
    cout << endl;
    return 0;
}   