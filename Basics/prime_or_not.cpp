#include<iostream>
using namespace std;

int main(){
    int n=11;
    bool isPrime = true;
    for(int i=2;i*i<=n;i++){  // i <= √n
        if(n%i==0){   //non-prime
           isPrime=false;
           break;
        }
    }
    if(isPrime == true){
        cout<<"Prime number"<<endl;
    }else{
        cout<<"Non-prime number";
    }
    

    return 0;
}
