#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = mp[s[s.size() - 1]];
        for (int i = s.size() - 2; i >= 0; i--)
        {
            if (mp[s[i]] < mp[s[i + 1]])
            {
                ans -= mp[s[i]];
            }
            else
            {
                ans += mp[s[i]];
            }
        }

        return ans;
    }
};

int main()
{
}

/*
FIXED CODE:

class Solution
{
public:
    int romanToInt(string s)
    {
        if (s.empty()) return 0;

        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = mp[s.back()];
        for (int i = s.size() - 2; i >= 0; i--)
        {
            int current = mp[s[i]];
            int next = mp[s[i + 1]];
            if (current < next)
            {
                ans -= current;
            }
            else
            {
                ans += current;
            }
        }

        return ans;
    }
};

Line 5–11: [style] Manual initialization of unordered_map is verbose; prefer initializer list for readability and conciseness.

Line 10: [style] Repeated use of mp[s[...]] leads to redundant hash lookups; consider caching mp[s[i]] and mp[s[i+1]] in variables for clarity and slight performance gain (though compiler may optimize).

*/