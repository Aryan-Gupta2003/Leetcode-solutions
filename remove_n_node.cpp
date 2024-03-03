#include <bits/stdc++.h>
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *d = new ListNode(0);
        d->next = head;
        ListNode *p = d;
        ListNode *q = d;

        for (int i = 0; i <= n; i++)
        {
            p = p->next;
        }

        while (p != nullptr)
        {
            p = p->next;
            q = q->next;
        }

        ListNode *temp = q->next;
        q->next = q->next->next;
        delete temp;

        return d->next;
    }
};

int main()
{
    Solution o1;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;

    ListNode *r = o1.removeNthFromEnd(head, n);
    cout << "List after removing " << n << "th node from the end: ";
    while (r != nullptr)
    {
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;

    return 0;
}