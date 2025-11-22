#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctype.h>

using namespace std;

bool isAlphaNum(char ch)
{
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
    {
        return true;
    }

    return false;
}

bool isPalindrome(string str)
{
    int st = 0, end = str.length() - 1;
    while (st < end)
    {
        if (!isAlphaNum(str[st]))
        {
            st++;
            continue;
        }
        if (!isAlphaNum(str[end]))
        {
            end--;
            continue;
        }
        if (tolower(str[st]) != tolower(str[end]))
        {
            return false;
        }
        st++;
        end--;
    }
    return true;
}

void display(int a)
{
    if (a == 1)
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

    string str1 = "Sanju";
    string str2 = "Ra#$ce(*caR)";

    display(isPalindrome(str1));
    display(isPalindrome(str2));
    

    return 0;
}