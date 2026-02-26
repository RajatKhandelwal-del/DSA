#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.length() == 0)
    {
        return 0;
    }
    int n = s.length();
    int finCount = INT_MIN;
    for (int idx = 0; idx < n; idx++)
    {
        vector<bool> alphabets(256, false);
        int count = 0;
        for (int i = idx; i < n; i++)
        {
            if (!alphabets[s[i]])
            {
                count++;
                alphabets[s[i]] = true;
            }
            else
            {
                break;
            }
            finCount = max(finCount, count);
        }
    }
    return finCount;
}