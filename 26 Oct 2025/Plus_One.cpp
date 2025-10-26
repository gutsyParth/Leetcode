#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry=1;
        int n=digits.size();

        for(int i=n-1;i>=0;i--)
        {
            digits[i]+=carry;
            carry=digits[i]/10;
            digits[i]%=10;
        }

        if(carry)
        {
            vector<int>ans;
            ans.push_back(carry);

            for(auto x:digits)
            {
                ans.push_back(x);
            }
            return ans;
        }
       
        return digits;
        
    }
};


