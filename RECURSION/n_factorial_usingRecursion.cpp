#include<iostream>
using namespace std;

int fact(int n){
    if(n==0) return 1;     // Base case
    
    return n*fact(n-1);    // find factorial for each level
}

int main(){
    int n = 5;
    
    cout << fact(n) << endl;

    return 0;
}