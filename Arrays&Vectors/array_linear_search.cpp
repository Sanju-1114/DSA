#include<iostream>
using namespace std;

int linearSearch(int arr[],int sz,int target){      //function for linear search
for(int i=0;i<sz;i++){
     if(arr[i]==target){
        return i;
     }
   }
    return -1;
}

int main(){
   int arr[]={2,4,7,8,1,2,5};
   int target=8;
   int sz=sizeof(arr)/sizeof(int);
                                                 
   int ans = linearSearch(arr,sz,target);    //function call for linear search
   cout<<ans<<endl;

    return 0;
}    