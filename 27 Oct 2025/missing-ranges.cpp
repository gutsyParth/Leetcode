#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findMissingRanges(vector<int> &nums, int lower, int upper)
    {
        int l = lower;
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] - l >= 1)
            {
                ans.push_back({l, nums[i] - 1});
            }
            l = nums[i] + 1;
        }

        if (upper - l >= 0)
        {
            ans.push_back({l, upper});
        }

        return ans;
    }
};

int main()
{
}