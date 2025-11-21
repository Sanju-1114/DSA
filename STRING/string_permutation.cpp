#include <iostream>

using namespace std;

bool isFreqSame(int freq1[], int freq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return false;
        }
    }
    return true;
}

bool isPermutationExist(string str, string bigStr)
{
    int freq[26] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        freq[str[i] - 'a']++;
    }

    int windowSize = str.length();

    for (int i = 0; i < bigStr.length(); i++)
    {
        int windowIdx = 0, idx = i;
        int windFreq[26] = {0};
        while (windowIdx < windowSize && idx < bigStr.length())
        {
            windFreq[bigStr[idx] - 'a']++;
            windowIdx++;
            idx++;
        }
        if (isFreqSame(freq, windFreq) == true)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string part = "abc";
    string str = "daabcmsbndadc";

    cout << isPermutationExist(part, str) << endl;

    return 0;
}