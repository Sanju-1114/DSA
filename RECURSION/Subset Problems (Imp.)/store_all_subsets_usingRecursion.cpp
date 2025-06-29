// LeetCode problem 78
#include <iostream>
#include <vector>
using namespace std;     
                              // TC : O(2^n *n) 
void getAllSubsets(vector<int> &arr , vector<int> &ans , int i , vector<vector<int>> &allSubsets){     
     if(i == arr.size()){
        allSubsets.push_back({ans});  //push all values in the anas array
        return;
     }  

     // Include
     ans.push_back(arr[i]);
     getAllSubsets(arr,ans,i+1 ,allSubsets);
     
     ans.pop_back(); // Backtrack
     //Exclude
     getAllSubsets(arr , ans , i+1, allSubsets);

}

vector<vector<int>> subsets(vector<int> &arr){
    vector<vector<int>> allSubsets;
    vector<int> ans;
    getAllSubsets(arr , ans , 0 , allSubsets);

    return allSubsets; 
}


int main()
{
    vector<int> arr = {1,2,3};
    vector<int>ans;   // Store subsets

    for(vector<int> val : subsets(arr)){
       for(int ins : val){
          cout << ins << " ";
       }
       cout << endl;
    }
    subsets(arr);

    return 0;
}