// LeetCode problem 39
#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

set<vector<int>> s;  // to remove duplicate combinations

//helper function
void getAllCombinations(vector<int> &arr,int idx,int target,vector<vector<int>> &ans,vector<int> &combination){
     
    if(idx == arr.size() || target < 0){
        return;
    }

    if(target == 0){
        if(s.find(combination) == s.end()){
            ans.push_back({combination});
            s.insert(combination);
        }
        return;
    }

    combination.push_back(arr[idx]);
    // single
    getAllCombinations(arr , idx+1 , target-arr[idx] , ans , combination);
    // multiples
    getAllCombinations(arr , idx , target-arr[idx] , ans , combination);
    combination.pop_back();

    //exclusion
    getAllCombinations(arr , idx+1 , target , ans , combination);
    


}

vector<vector<int>> combinationSum(vector<int> &arr , int target){
    vector<vector<int>> ans;
    vector<int> combination; 
    
    getAllCombinations(arr , 0 , target , ans , combination);

    return ans;
}

int main(){
    vector<int> arr = {2,3,5};
    int target = 8;

    
    for(vector<int> comb : combinationSum(arr , target)){
        for(int val : comb){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}