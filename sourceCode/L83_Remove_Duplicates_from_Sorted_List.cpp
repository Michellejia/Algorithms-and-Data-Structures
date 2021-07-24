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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *prevNode = head;
        ListNode *res = head;
        unordered_set<int> us;
        if (head == nullptr || head->next == nullptr)
            return head;

        us.insert(head->val);
        head = head->next;
        while (head != nullptr)
        {
            if (us.find(head->val) != us.end())
                prevNode->next = head->next;
            else
            {
                us.insert(head->val);
                prevNode = head;
            }
            head = head->next;
        }
        return res;
    }
};

int main()
{
    ListNode a1(1);
    ListNode a2(1);
    ListNode a3(3);
    ListNode a4(3);
    ListNode a5(3);
    ListNode a6(4);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    a5.next = &a6;

    Solution s;
    ListNode *res = s.deleteDuplicates(&a1);
    while (res != nullptr)
    {
        printf("%d\n", res->val);
        res = res->next;
    }
}