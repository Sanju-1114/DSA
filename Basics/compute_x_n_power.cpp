 // using binary exponential

#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    long binaryForm = n;
    double ans = 1;

    if (n == 0)
        return 1.0;
    if (x == 1)
        return 1.0;
    if (x == 0)                                   // corner cases
        return 0.0;
    if (x == -1 && n % 2 == 0)
        return 1.0;
    if (x == -1 && n % 2 != 0)
        return -1.0;


    if (n < 0)
    {
        x = 1 / x;
        binaryForm = -n;
    }
    while (binaryForm > 0)                     // calculate power
    {
        if (binaryForm % 2 == 1)
        {
            ans *= x;
        }
        x *= x;
        binaryForm /= 2;
    }
    return ans;
}


int main()
{
   
    double decNum = 2;                               //inputs
    int n = 3;

    cout << "x^n = " << myPow(decNum, n) << endl;     //function call ans display result

    return 0;
}