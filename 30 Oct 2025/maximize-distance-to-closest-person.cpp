#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int n = seats.size();

        vector<int> prefix(n, -1);
        vector<int> suffix(n, n);

        for (int i = 0; i < n; i++)
        {
            if (seats[i])
            {
                prefix[i] = i;
            }
            else
            {
                if (i == 0)
                {
                    prefix[i] = -1;
                }
                else
                {
                    prefix[i] = prefix[i - 1];
                }
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (seats[i])
            {
                suffix[i] = i;
            }
            else
            {
                if (i == n - 1)
                {
                    suffix[i] = -1;
                }
                else
                {
                    suffix[i] = suffix[i + 1];
                }
            }
        }

        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            if (prefix[i] == -1)
            {
                ans = max(ans, suffix[i] - i);
            }
            else if (suffix[i] == -1)
            {
                ans = max(ans, i - prefix[i]);
            }
            else
            {
                ans = max(ans, min(i - prefix[i], suffix[i] - i));
            }
        }

        return ans;
    }
};

/*

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int n = seats.size();
        int left = -1; // Index of closest person to the left
        int maxDist = 0;

        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 1)
            {
                if (left == -1)
                {
                    // First person: distance is from start to this person
                    maxDist = i;
                }
                else
                {
                    // Between two people: max distance is half the gap
                    maxDist = max(maxDist, (i - left) / 2);
                }
                left = i;
            }
        }

        // Handle trailing zeros (after last person)
        if (seats[n - 1] == 0)
        {
            maxDist = max(maxDist, n - 1 - left);
        }

        return maxDist;
    }
};

*/