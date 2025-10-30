#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        for (int i = 1; i < n; i++)
        {
            prefix[i] = max(prefix[i - 1], height[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = max(suffix[i + 1], height[i]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (height[i] < prefix[i] && height[i] < suffix[i])
            {
                cout << i << " " << min(prefix[i], suffix[i]) - height[i] << "\n";
                ans += min(prefix[i], suffix[i]) - height[i];
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> v = {4, 2, 0, 3, 2, 5};

    Solution S;
    cout << S.trap(v);
}