#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists_v1(ListNode *l1, ListNode *l2)
    {
        // ListNode *newHead;
        // ListNode *newHead = new ListNode(0);
        ListNode *newHead = (ListNode *)malloc(sizeof(ListNode));
        ListNode *res = newHead;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                newHead->next = l1;
                l1 = l1->next;
            }
            else
            {
                newHead->next = l2;
                l2 = l2->next;
            }
            newHead = newHead->next;
        }

        newHead->next = l1 == nullptr ? l2 : l1;

        return res->next;
    }

    // recursive
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main()
{
    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(4);
    // ListNode a4(-4);
    a1.next = &a2;
    a2.next = &a3;
    // a3.next = &a4;
    // a2.next = &a1;

    ListNode a11(1);
    ListNode a21(3);
    ListNode a31(4);
    // ListNode a4(-4);
    a11.next = &a21;
    a21.next = &a31;
    // a3.next = &a4;
    // a2.next = &a1;
    Solution s;
    ListNode *res = s.mergeTwoLists(&a1, &a11);
    while (res != nullptr)
    {
        printf("%d\n", res->val);
        res = res->next;
    }
}