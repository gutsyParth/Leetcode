#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 1;
        }

        int idx1 = 0;
        int idx2 = 1;

        while (idx2 < nums.size())
        {
            if (nums[idx1] == nums[idx2])
            {
                idx2++;
            }
            else
            {
                idx1++;
                nums[idx1] = nums[idx2];
            }
        }

        return idx1 + 1;
    }
};

int main()
{
}