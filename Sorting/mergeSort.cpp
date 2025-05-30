// LeetCode problem 
#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

void merge(vector<int> &arr , int st , int mid , int end){  // TC : O(n)
    vector<int> temp;

    int i=st , j=mid+1;

    while (i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }

    while (i<=mid){
        temp.push_back(arr[i++]);
    }

    while(j<=end){
        temp.push_back(arr[j++]);
    }
    
    for(int idx = 0 ; idx < temp.size() ; idx++){
        arr[idx+st] = temp[idx];
    }

}

void mergeSort(vector<int> &arr , int start , int end){  // TC:O(nlogn)  => TC of merge sort total  
    if (start < end){                                    // SC : O(n)
        int mid = start + (end - start)/2;
        mergeSort(arr , start , mid);  // left part
        mergeSort(arr , mid+1 , end);  // right part    
        
        merge(arr , start , mid , end);
    }
    
}

int main(){
    vector<int> arr = {12,31,35,8,32,17};

    mergeSort(arr , 0 , arr.size()-1);

    for(int val : arr){
        cout << val << " ";
    }
    
    cout << endl;

    return 0;
}