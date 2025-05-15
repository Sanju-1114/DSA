#include<iostream>
using namespace std;

int main(){

   //test for loop 
    // int n=5;
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

  //sum of numbers from 1 to n
   int n=10;
   int sum=0;
   for(int i=1;i<=n;i++){
      sum+=i;
   }
   cout<<"Sum = "<<sum<<endl;
   
    return 0;
}