#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        int idx1 = -1;
        int idx2 = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.count(target - nums[i]))
            {
                idx1 = mp[target - nums[i]];
                idx2 = i;
                break;
            }
            mp[nums[i]] = i;
        }

        return {idx1, idx2};
    }
};

int main()
{
}

/*
NOTES:
1. map: Implemented as a Red-Black Tree (a self-balancing binary search tree).
2. unordered_map: Implemented as a hash table.
3. Operation	map (Ordered)	        unordered_map (Hash)
   Insertion	O(log n)	            O(1) average, O(n) worst*
   Lookup	    O(log n)	            O(1) average, O(n) worst*
   Deletion	    O(log n)	            O(1) average, O(n) worst*
   Iteration	O(n) (in sorted order)	O(n) (in arbitrary order)

*/