#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *p = head;
        ListNode *q = head;
        while (p != nullptr && p->next != nullptr)
        {
            p = (p->next)->next;
            q = q->next;

            if (p == q)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution o1;
    ListNode *head = new ListNode(3);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(0);
    ListNode *fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;

    bool result = o1.hasCycle(head);
    cout << "Linked list has cycle : " << (result == 1 ? "True" : "False") << endl;
    return 0;
}