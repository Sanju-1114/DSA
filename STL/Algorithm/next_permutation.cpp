#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    string s="abc";
    next_permutation(s.begin() , s.end());
    cout << s << endl;

    string s2="bca";
    prev_permutation(s2.begin() , s2.end());
    cout << s2 << endl;

    return 0;
}