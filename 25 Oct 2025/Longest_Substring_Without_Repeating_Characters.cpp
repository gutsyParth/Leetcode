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

int main()
{
    vector<int> v={1,8,6,2,5,4,8,3,7};
    Solution S;
    cout<<S.maxArea(v);
}

