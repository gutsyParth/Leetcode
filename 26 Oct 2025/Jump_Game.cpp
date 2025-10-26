#include <iostream>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n =nums.size();
        int tgt = n-1;

        for(int i=n-2;i>=0;i--)
        {
            if(i+nums[i]>=tgt)
            {
                tgt=i;
            }
        }

        if(tgt==0)
        {
            return true;
        }
        return false;
    }
};


int main()
{
    Solution S;
    vector<int>v={3,2,1,0,4};
    cout<<S.canJump(v);
}

/*
Took a lot of time.
Lesson learnt:
1. Don't get stuck
2. If something is not working don't beat the bush around that thinking only try something else.
*/