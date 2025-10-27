#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool check(unordered_map<char, int> &mp)
    {
        int cnt = 0;

        for (auto x : mp)
        {
            if (x.second)
            {
                cnt += 1;
            }
        }

        if (cnt > 2)
            return true;

        return false;
    }

    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        int st = 0, en = 0;

        int n = s.size();

        unordered_map<char, int> mp;

        for (char i = 'a'; i <= 'z'; i++)
        {
            mp[i] = 0;
        }

        for (char i = 'A'; i <= 'Z'; i++)
        {
            mp[i] = 0;
        }

        int ans = 0;

        while (en < n)
        {
            mp[s[en]] += 1;

            while (check(mp))
            {
                mp[s[st]] -= 1;
                st++;
            }

            ans = max(ans, en - st + 1);
            en++;
        }

        return ans;
    }
};

int main()
{
    Solution S;
    cout << S.lengthOfLongestSubstringTwoDistinct("ccaabbb");
}

/*
Optimized Code:
class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        int st = 0, en = 0;
        int n = s.size();
        unordered_map<char, int> mp; // Only store characters that appear
        int ans = 0;

        while (en < n)
        {
            mp[s[en]]++; // Expand window

            // Shrink window if more than 2 distinct characters
            while (mp.size() > 2)
            {
                mp[s[st]]--;
                if (mp[s[st]] == 0)
                    mp.erase(s[st]); // Remove key to keep size accurate
                st++;
            }

            ans = max(ans, en - st + 1);
            en++;
        }

        return ans;
    }
};

*/