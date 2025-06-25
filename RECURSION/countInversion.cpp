// Count Inversion
//  Conditions for that
//      1. i < j
//      2. arr[i] > arr[j]



#include <iostream> 
#include<vector>
using namespace std;

// // Brute Force Approach         TC : O(n^2)
// int countInversion(vector<int> &arr){
//     int n = arr.size();
//     int invCount = 0;
//     for(int i=0 ; i < n ; i++){
//         for(int j = i+1 ; j<n ; j++){
//             if(arr[i] > arr[j]){
//              invCount++;
//             }
//         }
//     }
//     return invCount;
// }

// Optimal approach           //** -> changes on that lines in mergeSort code for inversion count
int merge(vector<int> &arr , int st , int mid , int end){  // TC : O(n)
    vector<int> temp;

    int i=st , j=mid+1;
    int invCount = 0;                   //**
    while (i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
            invCount += mid-i+1;        // (mid-i+1) itna inversion milega ek bar me   //** 
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
    return invCount;                              //**
}

int mergeSort(vector<int> &arr , int start , int end){  // TC:O(nlogn)  => TC of merge sort total  
    if (start < end){                                    // SC : O(n)
        int mid = start + (end - start)/2;

        int leftInvCount = mergeSort(arr , start , mid);  // left part      //**
        int rightInvCount = mergeSort(arr , mid+1 , end);  // right part      //**
        
        int invCount = merge(arr , start , mid , end);            //**

        return leftInvCount + rightInvCount + invCount ;            //**
    }
    return 0;                                    //**
}


int main() {
   
    vector<int> arr = {6, 3, 5, 2, 7};
    int ans = mergeSort(arr , 0 , arr.size()-1);
    cout << "Inversion count : " << ans << endl;

    return 0; 
}