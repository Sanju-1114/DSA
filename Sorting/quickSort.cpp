// LeetCode problem 
#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

int partition(vector<int> &arr , int st , int end){
    int idx = st-1;
    int pivot = arr[end];

    for(int j=st ; j<end ; j++){
        if(arr[j] <= pivot){
            idx++;
            swap(arr[j] , arr[idx]);
        }
    }
    idx++;
    swap(arr[idx] , arr[end]);

    return idx;
}

void quickSort(vector<int> &arr , int start , int end){  // Avg./Practical cases => TC : O(nlogn)
    if (start < end){                                    //           Worst case => TC : O(n^2)  
        int pivotIdx = partition(arr , start , end);     // SC : O(1)  => ignoring recursion call stack

        quickSort(arr , start , pivotIdx-1); //left
        quickSort(arr , pivotIdx+1 , end);  //right     
    }
      
    
}

int main(){
    vector<int> arr = {12,31,35,8,32,17};

    quickSort(arr , 0 , arr.size()-1);

    for(int val : arr){
        cout << val << " ";
    }
    
    cout << endl;

    return 0;
}