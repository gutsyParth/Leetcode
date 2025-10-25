#include<iostream>
using namespace std;

class Solution {
    public:
        int helper(vector<int>& arr)
        {
            vector<pair<int,int>>arr_with_idx;

            for(int i=0;i<arr.size();i++)
            {
                arr_with_idx.push_back(make_pair(arr[i],i));
            }

            sort(arr_with_idx.begin(),arr_with_idx.end());

            int ans=0;

            int mx_idx=arr_with_idx[arr.size()-1].second;

            for(int i=arr.size()-1;i>=0;i--)
            {
                if(mx_idx>arr_with_idx[i].second)
                {
                    ans=max(ans,arr_with_idx[i].first*(mx_idx-arr_with_idx[i].second));
                }
                mx_idx=max(mx_idx,arr_with_idx[i].second);
            }

            return ans;
        }

        int maxArea(vector<int>& height) {
            int ans1=helper(height);
            reverse(height.begin(),height.end());
            int ans2=helper(height);
            return max(ans1,ans2);
        }
    };


/*
OPTIMIZED SOLUTION:

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;

        while (left < right) {
            // Calculate area with current container
            int width = right - left;
            int h = min(height[left], height[right]);
            ans = max(ans, width * h);

            // Move the pointer pointing to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};

Start with the widest possible container (first and last elements).
At each step, move the pointer with the smaller height inward, because moving the taller one cannot increase the area (width decreases and height is still capped by the shorter one).

Proof:

We start with the widest container, l = 0 and r = n - 1. Let's say the left one is shorter: h[l] < h[r]. Then, this is already the largest container the left one can possibly form. There's no need to consider it again. Therefore, we just throw it away and start again with l = 1 and r = n -1.
*/