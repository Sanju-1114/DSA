#include<iostream>
#include<vector>
using namespace std;

int reverseArray( vector<int>& vec){          //function to revevrse an elements of array
    int i,j;
    for( i=0,j=(vec.size()-1);i<j;i++,j--){          //code to reverse the array
         swap(vec[i],vec[j]);
    }
}

int main(){
   vector<int>vec={4,2,7,8,1,2,5};
  
   reverseArray(vec);                //function call to reverse an array
   
   for(int val:vec){             
    cout<<val<<" ";                 //print the reversed array
   }

    return 0;
}