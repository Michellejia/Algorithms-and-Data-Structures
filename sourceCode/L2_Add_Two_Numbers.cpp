#include <iostream>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode();
        // If only declare ListNode *res, the following is illegal. If res is not initialized
        // and use it to initialize others. The addresses of head and res are inconsistent.
        ListNode *head = res;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr)
        {
            // res = new ListNode();
            res->val = l1->val + l2->val + carry;
            if (res->val >= 10)
            {
                res->val -= 10;
                carry = 1;
            }
            else
                carry = 0;
            l1 = l1->next;
            l2 = l2->next;
            if (l1 && l2)
            {
                res->next = new ListNode();
                res = res->next;
            }
        }
        while (l1)
        {
            res->next = new ListNode();
            res = res->next;
            res->val = carry + l1->val;
            if (res->val >= 10)
            {
                res->val -= 10;
                carry = 1;
            }
            else
                carry = 0;
            l1 = l1->next;
        }
        while (l2)
        {
            res->next = new ListNode();
            res = res->next;
            res->val = carry + l2->val;
            if (res->val >= 10)
            {
                res->val -= 10;
                carry = 1;
            }
            else
                carry = 0;
            l2 = l2->next;
        }
        if (carry)
        {
            res->next = new ListNode();
            res = res->next;
            res->val = 1;
        }
        return head;
    }
};

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* head = l1, *prev = NULL;
//         int carry = 0;
//         bool set = false;

//         while(l1 != NULL && l2 != NULL){
//             if((l1->val + l2->val + carry) >= 10)
//                 l1->val += l2->val + carry - 10, carry = 1;
//             else
//                 l1->val += l2->val + carry, carry = 0;
//             prev = l1;
//             l1 = l1->next;
//             l2 = l2->next;
//         }

//         while(l1 != NULL){
//             if((l1->val + carry) >= 10)
//                 l1->val += carry - 10, carry = 1;
//             else
//                 l1->val += carry, carry = 0;
//             prev = l1;
//             l1 = l1->next;

//         }

//         while(l2 != NULL){
//             if(set == false)
//                 prev->next = l2, set = true;
//             if((l2->val + carry) >= 10)
//                 l2->val += carry - 10, carry = 1;
//             else
//                 l2->val += carry, carry = 0;
//             prev = l2;
//             l2 = l2->next;
//         }

//         if(carry == 1){
//             ListNode* lastNode = new ListNode();
//             lastNode->val = 1;
//             prev->next = lastNode;
//         }

//         return head;
//     }
// };

int main()
{
    Solution s;
    ListNode *l1 = new ListNode(0);
    // ListNode *b1 = new ListNode(4);
    // ListNode *c1 = new ListNode(3);
    // ListNode *d1 = new ListNode(9);
    // ListNode *e1 = new ListNode(9);
    // ListNode *f1 = new ListNode(9);
    // ListNode *g1 = new ListNode(9);
    // l1->next = b1;
    // b1->next = c1;
    // c1->next = d1;
    // d1->next = e1;
    // e1->next = f1;
    // f1->next = g1;

    ListNode *l2 = new ListNode(0);
    // ListNode *b2 = new ListNode(6);
    // ListNode *c2 = new ListNode(4);
    // ListNode *d2 = new ListNode(9);
    // l2->next = b2;
    // b2->next = c2;
    // c2->next = d2;

    ListNode *res = s.addTwoNumbers(l1, l2);
    while (res != nullptr)
    {
        std::cout << res->val << endl;
        res = res->next;
    }
}
