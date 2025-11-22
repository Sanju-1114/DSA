#include <iostream>
#include <vector>
using namespace std;

int stringCompression(vector<char> &chars)
{
    int n = chars.size(), idx = 0;    // idx to restore the digit and count in same vector
    for (int i = 0; i < n; i++)
    {
        char ch = chars[i];
        int count = 0;
        while (i < n && chars[i] == ch)
        {
            count++;
            i++;
        }
        if (count == 1)
        {
            chars[idx++] = ch;
        }
        else
        {
            chars[idx++] = ch;
            string str = to_string(count);
            for (char dig : str)
            {
                chars[idx++] = dig;
            }
        }
        i--;                     //  used to encounter the i++ in for loop
    }
    chars.resize(idx);          // used to resize the new vector
    return idx;
}

int main()
{                                                           // compress it like {a2b2c3} it is the character and how many times it occures
    vector<char> str = {'a', 'a', 'b', 'b', 'c', 'c', 'c'}; // And return the size of the string or length of string --> 6(in this case)

    cout << stringCompression(str) << endl;

    return 0;
}