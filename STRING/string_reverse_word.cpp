#include <iostream>
#include <algorithm>

using namespace std;

string reverseWord(string str)
{
    reverse(str.begin(), str.end());
    int n = str.length();
    string ansStr;
    for (int i = 0; i < n; i++)
    {
        string word = "";
        while (i < n && str[i] != ' ')
        {
            word += str[i];
            i++;
        }
        reverse(word.begin(), word.end());

        
        if (word.length() > 0)
        {
            ansStr += " " + word;
        }
    }
    return ansStr.substr(1);      // --> substr is the starting point from where string starts to return  == here 1 denotes that string starts
                                                                                                    //      returning from 1 instead of 0.  
}

int main()
{
    string str = "Sanju Bhai";

    cout << reverseWord(str) << endl;

    return 0;
}