#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            int tgt = nums[i];

            int st = i + 1;
            int en = n - 1;

            while (st < en)
            {
                if ((tgt + nums[st] + nums[en]) == 0)
                {
                    
                    int a = nums[st];
                    int b = nums[en];
            
                    while (st < en && nums[st] == a)
                    {
                        st++;
                    }

                    while (st < en && nums[en] == b)
                    {
                        en--;
                    }
                  
                    ans.push_back({tgt, a, b});
                  
                }
                else if (tgt + nums[st] + nums[en] < 0)
                {
                    st++;
                }
                else
                {
                    en--;
                }
            }

            while(i+1<n && nums[i+1]==tgt)
            {
                ++i;
            }
        }

        return ans;
    }
};

int main()
{
    Solution S;
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = S.threeSum(v);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}


/*
OPTIMIZED SOLUTION:

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) // Stop early: need at least 3 elements
        {
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue; // Skip duplicates for first element

            int tgt = -nums[i]; // Target sum for two-sum
            int st = i + 1;
            int en = n - 1;

            while (st < en)
            {
                int sum = nums[st] + nums[en];
                if (sum == tgt)
                {
                    ans.push_back({nums[i], nums[st], nums[en]});
                    
                    // Skip duplicates for second and third elements
                    while (st < en && nums[st] == nums[st + 1]) st++;
                    while (st < en && nums[en] == nums[en - 1]) en--;
                    
                    st++;
                    en--;
                }
                else if (sum < tgt)
                {
                    st++;
                }
                else
                {
                    en--;
                }
            }
        }

        return ans;
    }
};

*/