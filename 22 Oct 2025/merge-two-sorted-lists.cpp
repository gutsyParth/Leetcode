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
        
        ListNode *head2 = list2;
        
        ListNode *ans = nullptr;

        while (head1 && head2)
        {
            if(head1->next and head2->val <= head1->next->val)
            {
                if(ans==nullptr)
                {
                    ans=head1;
                }
                ListNode* temp = head1;
                head1 = head1->next;
                temp->next=head2;

                while(head2->next && head2->next->val <= head1->val)
                {
                    head2=head2->next;
                }

                if(head2->next == nullptr)
                {
                    head2->next = head1;
                    break;
                }
            }
            else if(head2->next and head1->val <= head2->next->val)
            {
                if(ans==nullptr)
                {
                    ans=head2;
                }
                ListNode* temp = head2;
                head2 = head2->next;
                temp->next=head1;

                while(head1->next && head1->next->val <= head2->val)
                {
                    head1=head1->next;
                }

                if(head1->next == nullptr)
                {
                    head1->next = head2;
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
}
