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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prevNode;
        ListNode *nextNode;
        if (head == nullptr || head -> next == nullptr)
            return head;
        if (head->next != nullptr)
        {
            prevNode = head;
            head = head->next;
            nextNode = head->next;
            prevNode->next = nullptr;
        }

        while (head != nullptr)
        {
            head->next = prevNode;
            prevNode = head;
            if (nextNode != nullptr)
            {
                head = nextNode;
                nextNode = nextNode->next;
            }
            else
                break;
        }
        return head;
    }
};

int main()
{
    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(3);
    ListNode a4(4);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;

    Solution s;
    ListNode *res = s.reverseList(&a1);
    while (res != nullptr)
    {
        printf("%d\n", res->val);
        res = res->next;
    }
}