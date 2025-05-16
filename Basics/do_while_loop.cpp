#include<iostream>
using namespace std;

int main(){
    int count=1,n=5;
    
  //Syntax
  // do
  // {
  //   /* code */
  // } while (condition);
  
    do{
        cout<<count<<" ";
        count++;
    }
    while(count<=n);
    
  cout<<endl;
    return 0;
}