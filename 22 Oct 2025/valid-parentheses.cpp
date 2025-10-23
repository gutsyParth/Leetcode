#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                else if (st.top() == '{' and s[i] == '}')
                {
                    st.pop();
                }
                else if (st.top() == '[' and s[i] == ']')
                {
                    st.pop();
                }
                else if (st.top() == '(' and s[i] == ')')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

/*
NOTES:
 Use of and instead of &&; while valid in C++ (via <iso646.h>), it is non-idiomatic and rarely used in modern C++ codebases.
*/

int main()
{
}
