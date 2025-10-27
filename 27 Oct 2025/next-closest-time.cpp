#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string nextClosestTime(string time)
    {
        vector<string> temp;

        for (int i = 0; i < 24; i++)
        {
            string x = "";
            if (i < 10)
            {
                x += "0";
                x += char('0' + i);
            }
            else
            {
                x += to_string(i);
            }
            for (int j = 0; j < 60; j++)
            {
                string xx = x;
                if (j < 10)
                {
                    xx += ":0";
                    xx += char('0' + j);
                }
                else
                {
                    xx += ":";
                    xx += to_string(j);
                }
                temp.push_back(xx);
            }
        }

        bool flag = false;
        int idx = 0;

        for (int i = 0; i < temp.size(); i++)
        {
            if (flag)
            {
                idx += i;
                idx = idx % temp.size();
                break;
            }

            if (temp[i] == time)
            {
                flag = true;
            }
        }

        while (1)
        {
            flag = true;
            for (auto x : temp[idx])
            {
                if (time.find(x) == string::npos)
                {
                    idx += 1;
                    idx = idx % temp.size();
                    flag = false;
                    break;
                }
            }

            if (flag)
                return temp[idx];
        }

        return "00:00";
    }
};

int main()
{
    Solution S;
    cout << S.nextClosestTime("19:34");
}

/*
Optimized Code:
class Solution
{
public:
    string nextClosestTime(string time)
    {
        // Extract allowed digits
        unordered_set<char> allowed = {time[0], time[1], time[3], time[4]};

        // Convert current time to total minutes
        int minutes = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));

        while (true)
        {
            minutes = (minutes + 1) % (24 * 60); // Move to next minute (wrap around)

            // Format candidate time as "HH:MM"
            int h = minutes / 60;
            int m = minutes % 60;
            string candidate =
                (h < 10 ? "0" : "") + to_string(h) + ":" +
                (m < 10 ? "0" : "") + to_string(m);

            // Check if all digits in candidate are allowed
            if (allowed.count(candidate[0]) &&
                allowed.count(candidate[1]) &&
                allowed.count(candidate[3]) &&
                allowed.count(candidate[4]))
            {
                return candidate;
            }
        }
    }
};
*/