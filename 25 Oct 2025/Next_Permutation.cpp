#include<iostream>
using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int n=nums.size();
        
            for(int i=n-2;i>=0;i--)
            {
                int mn=nums[i];
                int idx=-1;
                for(int j=i+1;j<n;j++)
                {
                    if(nums[j]>mn)
                    {
                        mn=min(mn,nums[i]);
                        idx=j;
                    }
                }
                if(idx!=-1)
                {
                    swap(nums[idx],nums[i]);
                    sort(nums.begin()+i+1,nums.end());
                    return;
                }
            }
            sort(nums.begin(),nums.end());
        }
};

int main()
{
    Solution S;
    vector<int>v={1,5,1};
    S.nextPermutation(v);

    for(auto x:v)
    {
        cout<<x<<" ";
    }
}

/*
Optimized Code:

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the first index i from right where nums[i] < nums[i+1]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            // Step 2: Find the smallest element in suffix > nums[i]
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Step 3: Swap nums[i] and nums[j]
            swap(nums[i], nums[j]);
        }
        
        // Step 4: Reverse the suffix after i to get smallest lexicographic order
        reverse(nums.begin() + i + 1, nums.end());
    }
};

*/