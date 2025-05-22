#include<iostream>
using namespace std;

int main(){
   int a[5];
   int sz = sizeof(a)/sizeof(int);

   cout<<"Enter the elements of array : ";    //input elements of array
   for(int i=0;i<sz;i++){
     cin>>a[i];
   }
   cout<<"Entered elements of array : ";     // print the array
   for(int i=0;i<sz;i++){
    cout<<a[i]<<" ";
   }
    //  smallest in array
   int smallest = INT32_MAX;                  
   for(int i=0;i<sz;i++){
    //   if(a[i]<smallest){                 two ways to find the minimum value
    //     smallest = a[i];
    //   }  OR
        smallest = min(a[i],smallest);
        
   
   }
   cout<<"\nSmallest number : "<< smallest <<endl;

    return 0;
}