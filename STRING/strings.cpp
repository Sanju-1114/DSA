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
    isPalindrome(str);
    isPalindrome(str1);

    return 0;
}

// char str[14];
//     cout << "Enter the character array: ";
//     // cin >> str;                         // best for single word only not for whole sentence

//     cin.getline(str,14);
//     cout << "Output: " << str << endl;

//     //Length of the string
//     // int count=0;
//     // for(int i=0;i< str[i]!='\0'; i++){
//     //     count++;
//     // }
//     // cout << "Length of the string : " << count << endl;