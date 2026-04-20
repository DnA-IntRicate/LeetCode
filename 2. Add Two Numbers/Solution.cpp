#include <stack>

// Stub definition for singly-linked list.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        std::stack<int> s1, s2;

        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (!s1.empty() || !s2.empty() || carry)
        {
            int sum = carry;

            if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }

            ListNode* node = new ListNode(sum % 10);

            if (!head)
                head = tail = node;
            else
            {
                tail->next = node;
                tail = node;
            }

            carry = sum / 10;
        }

        return head;
    }
};
