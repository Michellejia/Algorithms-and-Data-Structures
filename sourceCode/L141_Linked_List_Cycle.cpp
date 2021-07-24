#include <iostream>
#include <unordered_set>
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
    bool hasCycle_v1(ListNode *head)
    {
        unordered_set<ListNode *> mp;
        while (mp.find(head) == mp.end() && head != nullptr)
        {
            mp.insert(head);
            head = head->next;
        }
        if (head == nullptr)
            return false;
        return true;
    }

    // Fast and slow pointer
    bool hasCycle(ListNode *head)
    {
        if(head == nullptr)
            return false;
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast != slow)
        {
            if (fast == nullptr || fast->next == nullptr)
                return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};

int main()
{
    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(0);
    ListNode a4(-4);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a2.next = &a1;
    Solution s;
    printf("%d\n", s.hasCycle(&a1));
}