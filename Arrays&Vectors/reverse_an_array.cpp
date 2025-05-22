#include<iostream>
using namespace std;

int reverseArray(int arr[],int sz){          //function to revevrse an elements of array
    int i,j;
    for( i=0,j=(sz-1);i<j;i++,j--){          //code to reverse the array
         swap(arr[i],arr[j]);
    }
}

int main(){
   int arr[]={4,2,7,8,1,2,5};
   int sz=sizeof(arr)/sizeof(int);   // to calculate the size of array

   reverseArray(arr,sz);                //function call to reverse an array
   
   for(int i=0;i<sz;i++){             
    cout<<arr[i]<<" ";                 //print the reversed array
   }

    return 0;
}