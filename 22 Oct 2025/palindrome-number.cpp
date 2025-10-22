#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 or (x != 0 and x % 10 == 0))
        {
            return false;
        }

        if (x == 0)
        {
            return true;
        }

        int digits = floor(log10(x)) + 1;

        digits /= 2;
        int rev = 0;
        while (digits)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
            digits--;
        }

        x = x / (pow(10, digits));

        if (rev == x or rev == x / 10)
        {
            return true;
        }

        return false;
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
    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0))
        {
            return false;
        }

        int rev = 0;
        while (x > rev)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return x == rev || x == rev / 10;
    }
};

*/