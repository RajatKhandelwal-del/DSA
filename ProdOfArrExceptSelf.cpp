#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int left = 1;
        int right = 1;
        int n = nums.size();
        vector<int> op(n, 1);
        for (int i = 1; i < n; i++)
        {
            left *= nums[i - 1];
            op[i] = left;
        }
        for (int j = n - 2; j >= 0; j--)
        {
            right *= nums[j + 1];
            op[j] *= right;
        }
        return op;
    }
};