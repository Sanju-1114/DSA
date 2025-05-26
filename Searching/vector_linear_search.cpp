#include<iostream>
#include<vector>
using namespace std;

int linearSearch( vector<int>vec,int target){      //function for linear search
int idx=0;
for(int val:vec){
     if(val==target){
        return idx;
     }
     idx++;
   }
    return -1;
}

int main(){
   vector<int>vec={2,4,7,8,1,2,5};
   int target=8;
 
                                                 
   int ans = linearSearch(vec,target);    //function call for linear search
   cout<<ans<<endl;

    return 0;
}    