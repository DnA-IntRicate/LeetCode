#include <algorithm>

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) noexcept
    {
        ListNode* res = new ListNode();
        return mergeTwoListsImpl(list1, list2, res);
    }

private:
    static constexpr ListNode* mergeTwoListsImpl(ListNode* l1, ListNode* l2, ListNode* res) noexcept
    {
        if (!l1 && !l2)
            return res;

        if (!l1)
        {
            // Add all l2 stuff and return
            while (l2)
            {
                *res = ListNode(l2->val, new ListNode());
                res = res->next;
                l2 = l2->next;
            }

            return res;
        }

        if (!l2)
        {
            // Add all l1 stuff and return
            while (l1)
            {
                *res = ListNode(l1->val, new ListNode());
                res = res->next;
                l1 = l1->next;
            }

            return res;
        }

        *res = ListNode(std::min(l1->val, l2->val), new ListNode());
        return mergeTwoListsImpl(l1->next, l2->next, res->next);
    }
};
