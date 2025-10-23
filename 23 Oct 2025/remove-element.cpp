#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int idx1 = 0;

        for (int idx2 = 0; idx2 < nums.size(); idx2++)
        {
            if (nums[idx1] != val)
            {
                idx1++;
            }
            else if (nums[idx2] != val)
            {
                swap(nums[idx1], nums[idx2]);
                idx1++;
            }
        }

        return idx1;
    }
};

int main()
{
}

/*
OPTIMIZED CODE:

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int idx1 = 0; // Slow pointer: tracks position for next valid element

        for (int idx2 = 0; idx2 < nums.size(); ++idx2) // Fast pointer: scans all elements
        {
            if (nums[idx2] != val)
            {
                nums[idx1++] = nums[idx2]; // Copy valid element and advance slow pointer
            }
        }

        return idx1;
    }
};
*/