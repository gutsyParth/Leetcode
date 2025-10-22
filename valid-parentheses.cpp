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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        ListNode *head1 = list1;
        ListNode *head1nxt = list1->next;

        ListNode *head2 = list2;
        ListNode *head2nxt = list2->next;

        ListNode *ans = nullptr;

        while (head1 && head2)
        {
            if (head1->val <= head2->val && (head1nxt == nullptr || head2->val <= head1nxt->val))
            {
                if (ans == nullptr)
                {
                    ans = list1;
                }

                head1->next = head2;
                head1 = head1nxt;
                if (head1nxt != nullptr)
                    head1nxt = head1nxt->next;
                head2 = head2nxt;
                if (head2nxt != nullptr)
                    head2nxt = head2nxt->next;
            }
            else if (head2->val <= head1->val && (head2nxt == nullptr || head1->val <= head2nxt->val))
            {
                if (ans == nullptr)
                {
                    ans = list2;
                }

                head2->next = head1;
                head2 = head2nxt;
                if (head2nxt != nullptr)
                    head2nxt = head2nxt->next;
                head1 = head1nxt;
                if (head1nxt != nullptr)
                    head1nxt = head1nxt->next;
            }
            else if (head1->val <= head2->val)
            {
                head1 = head1nxt;
                if (head1nxt != nullptr)
                    head1nxt = head1nxt->next;
            }
            else if (head2->val <= head1->val)
            {
                head2 = head2nxt;
                if (head2nxt != nullptr)
                    head2nxt = head2nxt->next;
            }
        }

        return ans;
    }
};

/*

list1 =
[1,2,4]
list2 =
[1,3,4]

*/

int main()
{
}
