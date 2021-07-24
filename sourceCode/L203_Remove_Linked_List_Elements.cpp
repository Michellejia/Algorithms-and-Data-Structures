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
    ListNode *removeElements_v1(ListNode *head, int val)
    {
        ListNode *res = head;
        ListNode *prev = head;

        if (head == nullptr)
            return res;

        while (head->next != nullptr)
        {
            head = head->next;
            if (head->val == val)
                prev->next = head->next;
            else
                prev = prev->next;
        }

        if (res->val == val)
            res = res->next;

        return res;
    }

    // recursive
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return head;
        head->next = removeElements(head->next, val);
        if (head->val == val)
            return head->next;
        else
            return head;
    }
};

int main()
{
    ListNode a1(7);
    ListNode a2(7);
    ListNode a3(7);
    // ListNode a4(7);
    a1.next = &a2;
    a2.next = &a3;
    // a3.next = &a4;

    Solution s;
    ListNode *res = s.removeElements(&a1, 7);
    while (res != nullptr)
    {
        printf("%d\n", res->val);
        res = res->next;
    }
}