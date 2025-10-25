#include<iostream>
using namespace std;

class Solution {
    public:
        string multiply(string num1, string num2) {
            int n = num1.size()-1;
            int m = num2.size()-1;

            vector<int>ans(n+m+2,0);

            int idx=ans.size()-1;

            for(int i=m;i>=0;i--)
            {
                int carry_idx=idx;
                for(int j=n;j>=0;j--)
                {
                    int prod=((num1[j]-'0')*(num2[i]-'0'))%10;
                    int carry = ((num1[j]-'0')*(num2[i]-'0'))/10;

                    ans[carry_idx]+= prod;
                    carry_idx--;
                    ans[carry_idx]+= carry;
                }
                idx--;
            }

            for(int i=ans.size()-1;i>=1;i--)
            {
                ans[i-1]+=ans[i]/10;
                ans[i]=ans[i]%10;
            }

            string ans1="";
            int i=0;

            while(i<ans.size() && ans[i]==0)
            {
                i++;
            }

            for(int j=i;j<ans.size();j++)
            {
                ans1+=char(ans[j]+'0');
            }

            if(ans1=="")
            {
                return "0";
            }

            return ans1;
        }
    };

int main()
{
    Solution S;
    cout<<S.multiply("2","3");
}

/*
Optimized Code:

class Solution {
public:
    string multiply(string num1, string num2) {
        // Handle zero case early
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size(), m = num2.size();
        vector<int> ans(n + m, 0); // Max possible digits is n + m

        // Multiply each digit pair and accumulate in correct position
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1; // Positions in result array
                int sum = mul + ans[p2];

                ans[p2] = sum % 10;
                ans[p1] += sum / 10;
            }
        }

        // Convert result to string, skipping leading zeros
        string res = "";
        int i = 0;
        while (i < ans.size() && ans[i] == 0) i++;
        for (; i < ans.size(); i++) {
            res += char(ans[i] + '0');
        }

        return res;
    }
};
*/