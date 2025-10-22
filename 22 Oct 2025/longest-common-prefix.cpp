#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";
        int cur = 0;

        while (cur < strs[0].size())
        {
            char cur_ch = strs[0][cur];
            for (int i = 1; i < strs.size(); i++)
            {
                if (cur_ch != strs[i][cur] || cur == strs[i].size())
                {
                    return ans;
                }
            }
            cur++;
            ans += cur_ch;
        }

        return ans;
    }
};

int main()
{
}

/*
NOTES:
1. Initializing ans as "" is redundant; can be default-initialized as string ans;.
2. Variable name cur is non-descriptive; prefer index or pos for clarity (minor, but improves readability).
*/