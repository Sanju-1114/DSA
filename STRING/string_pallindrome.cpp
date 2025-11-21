#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool isPalindrome(string str)
{
    string str2 = str;
    reverse(str.begin(), str.end());
    // cout << str2 << endl;
    // cout << str << endl;
    if (str == str2)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
}

int main()
{

    string str = "Sanju";
    string str1 = "racecar";
    string str2 = "Ac3e3ca";
    isPalindrome(str);
    isPalindrome(str1);
    isPalindrome(str2);

    return 0;
}