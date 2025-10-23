#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        if (digits[digits.size() - 1] != 9)
        {
            digits[digits.size() - 1] += 1;
            return digits;
        }

        int i = digits.size() - 1;

        while (i >= 0)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i] += 1;
                return digits;
            }
            --i;
        }

        vector<int> ans(digits.size() + 1, 0);
        ans[0] = 1;

        return ans;
    }
};

int main()
{
}