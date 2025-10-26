#include <iostream>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size())
        {
            return "";
        }

        vector<int> s_arr(52, 0);

        for (int i = 0; i < t.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s_arr[s[i] - 'a']++;
            }
            else
            {
                s_arr[s[i] - 'A' + 26]++;
            }
        }

        vector<int> t_arr(52, 0);

        for (auto x : t)
        {
            if (x >= 'a' && x <= 'z')
            {
                t_arr[x - 'a']++;
            }
            else
            {
                t_arr[x - 'A' + 26]++;
            }
        }

        int st = 0, en = t.size() - 1;
        int siz = s.size();

        int ans_idx1 = -1;
        int ans_idx2 = -1;

        while (st < s.size() && en < s.size() && (en - st + 1) >= t.size())
        {
            bool flag = false;
            for (int i = 0; i < 52; i++)
            {
                if (t_arr[i] && t_arr[i] > s_arr[i])
                {
                    flag = true;
                    break;
                }
            }
            if (s[st] >= 'a' && s[st] <= 'z')
            {

                if (flag)
                {
                    en++;

                    if (en < s.size())
                    {
                        if (s[en] >= 'a' && s[en] <= 'z')
                            s_arr[s[en] - 'a'] += 1;
                        else
                            s_arr[s[en] - 'A' + 26] += 1;
                    }
                }
                else
                {
                    if ((en - st + 1) <= siz)
                    {
                        siz = en - st + 1;
                        ans_idx1 = st;
                        ans_idx2 = en;
                    }

                    if (st < s.size())
                    {
                        s_arr[s[st] - 'a'] -= 1;
                    }
                    st++;
                }
            }
            else
            {

                if (flag)
                {
                    en++;

                    if (en < s.size())
                    {
                        if (s[en] >= 'a' && s[en] <= 'z')
                            s_arr[s[en] - 'a'] += 1;
                        else
                            s_arr[s[en] - 'A' + 26] += 1;
                    }
                }
                else
                {
                    if ((en - st + 1) <= siz)
                    {
                        siz = en - st + 1;
                        ans_idx1 = st;
                        ans_idx2 = en;
                    }

                    if (st < s.size())
                    {
                        s_arr[s[st] - 'A' + 26] -= 1;
                    }
                    st++;
                }
            }
        }

        if (ans_idx1 == -1)
            return "";

        return s.substr(ans_idx1, ans_idx2 - ans_idx1 + 1);
    }
};

/*
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.length() == 0 || t.length() == 0)
        {
            return "";
        }
        // Dictionary which keeps a count of all the unique characters in t.
        unordered_map<char, int> dictT;
        for (int i = 0; i < t.length(); i++)
        {
            dictT[t[i]]++;
        }
        // Number of unique characters in t, which need to be present in the
        // desired window.
        int required = dictT.size();
        // Left and Right pointer
        int l = 0, r = 0;
        // formed is used to keep track of how many unique characters in t
        // are present in the current window in its desired frequency.
        // e.g. if t is "AABC" then the window must have two A's, one B and one
        // C. Thus formed would be = 3 when all these conditions are met.
        int formed = 0;
        // Dictionary which keeps a count of all the unique characters in the
        // current window.
        unordered_map<char, int> windowCounts;
        // ans list of the form (window length, left, right)
        int ans[3] = {-1, 0, 0};
        while (r < s.length())
        {
            // Add one character from the right to the window
            char c = s[r];
            windowCounts[c]++;
            // If the frequency of the current character added equals to the
            // desired count in t then increment the formed count by 1.
            if (dictT.find(c) != dictT.end() && windowCounts[c] == dictT[c])
            {
                formed++;
            }
            // Try and contract the window till the point where it ceases to be
            // 'desirable'.
            while (l <= r && formed == required)
            {
                c = s[l];
                // Save the smallest window until now.
                if (ans[0] == -1 || r - l + 1 < ans[0])
                {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }
                // The character at the position pointed by the
                // `Left` pointer is no longer a part of the window.
                windowCounts[c]--;
                if (dictT.find(c) != dictT.end() &&
                    windowCounts[c] < dictT[c])
                {
                    formed--;
                }
                // Move the left pointer ahead, this would help to look for a
                // new window.
                l++;
            }
            // Keep expanding the window once we are done contracting.
            r++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[2] - ans[1] + 1);
    }
};
*/