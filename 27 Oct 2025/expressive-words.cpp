#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<pair<char, int>> helper(string s)
    {
        vector<pair<char, int>> v;
        int idx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != s[idx])
            {
                v.push_back(make_pair(s[idx], i - idx));
                idx = i;
            }
        }

        v.push_back(make_pair(s[idx], s.size() - idx));

        return v;
    }

    int expressiveWords(string s, vector<string> &words)
    {

        vector<pair<char, int>> v = helper(s);
        int ans = 0;
        for (auto x : words)
        {
            vector<pair<char, int>> u = helper(x);

            if (u.size() != v.size())
            {
                continue;
            }

            bool flag = true;

            for (int i = 0; i < v.size(); i++)
            {
                if (u[i].first != v[i].first || (u[i].first == v[i].first && u[i].second != v[i].second && (v[i].second < 3 || v[i].second < u[i].second)))
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                ans += 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution S;

    string s = "dddiiiinnssssssoooo";
    vector<string> v = {"dinnssoo", "ddinso", "ddiinnso", "ddiinnssoo", "ddiinso", "dinsoo", "ddiinsso", "dinssoo", "dinso"};

    cout << S.expressiveWords(s, v);
}