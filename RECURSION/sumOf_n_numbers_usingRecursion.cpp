#include<iostream>
using namespace std;

int sumOfnumbers(int n){
    if(n==1) return 1;     // Base case
    
    return n + sumOfnumbers(n-1);    // find sum for each level
}

int main(){
    int n = 5;
    
    cout << sumOfnumbers(n) << endl;

    return 0;
}