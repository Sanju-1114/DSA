#include<iostream>
using namespace std;

int fibonacci(int n){             // TC : O(2^n)               SC:O(n)
    if(n==0 || n==1) return n;    // Base case
    
    return fibonacci(n-1) + fibonacci(n-2);    // find fibonacci term for each level
}

int main(){
    int n = 6;
    
    cout << fibonacci(n) << endl;

    return 0;
}



// Exact time complexity of the fibonacci is

                //      {(1.618)^n}  [Golden Ratio] 

                // This is also lnown as the [Golden Ratio]