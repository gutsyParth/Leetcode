#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }

        if (nums[mid] >= target)
        {
            return mid;
        }
        return mid + 1;
    }
};

int main()
{
}

/*
Optimized Approach:

Removed the post-loop conditional logic entirely.
Return left directly after the binary search loop.
Why? In binary search for insertion position:
left always ends up at the smallest index where nums[index] >= target.
This is exactly the required insertion point.
This is a well-known property of the standard binary search loop (while (left <= right)).

*/