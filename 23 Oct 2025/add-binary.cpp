#include <iostream>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans = "";

        int idx1 = a.size() - 1;
        int idx2 = b.size() - 1;
        int carry = 0;

        while (idx1 >= 0 && idx2 >= 0)
        {
            if (a[idx1] == '1' && b[idx2] == '1')
            {
                if (carry)
                {
                    ans = "1" + ans;
                }
                else
                {
                    ans = "0" + ans;
                    carry = 1;
                }
            }
            else if (a[idx1] == '0' && b[idx2] == '0')
            {
                if (carry)
                {
                    ans = "1" + ans;
                    carry = 0;
                }
                else
                {
                    ans = "0" + ans;
                }
            }
            else
            {
                if (carry)
                {
                    ans = "0" + ans;
                }
                else
                {
                    ans = "1" + ans;
                }
            }
            idx1--;
            idx2--;
        }

        while (idx1 >= 0)
        {
            if (a[idx1] == '1')
            {
                if (carry)
                {
                    ans = "0" + ans;
                }
                else
                {
                    ans = "1" + ans;
                }
            }
            else
            {
                if (carry)
                {
                    ans = "1" + ans;
                    carry = 0;
                }
                else
                {
                    ans = "0" + ans;
                }
            }

            idx1--;
        }

        while (idx2 >= 0)
        {
            if (b[idx2] == '1')
            {
                if (carry)
                {
                    ans = "0" + ans;
                }
                else
                {
                    ans = "1" + ans;
                }
            }
            else
            {
                if (carry)
                {
                    ans = "1" + ans;
                    carry = 0;
                }
                else
                {
                    ans = "0" + ans;
                }
            }

            idx2--;
        }

        if (carry)
        {
            return "1" + ans;
        }

        return ans;
    }
};

int main()
{
}

/*
NOTES:

Major inefficiency: Repeatedly prepending to the result string with ans = "X" + ans, which is O(k) per operation (where k is current length), leading to O((n+m)²) total time due to string reallocations.

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans = "";
        int idx1 = a.size() - 1;
        int idx2 = b.size() - 1;
        int carry = 0;

        while (idx1 >= 0 || idx2 >= 0 || carry)
        {
            int sum = carry;
            if (idx1 >= 0) sum += a[idx1--] - '0';
            if (idx2 >= 0) sum += b[idx2--] - '0';

            ans = char('0' + (sum % 2)) + ans; // Append current bit
            carry = sum / 2; // Update carry
        }

        return ans;
    }
};

*/