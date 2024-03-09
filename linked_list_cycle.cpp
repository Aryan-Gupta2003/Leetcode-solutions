// Leetcode problem statement link
// https://leetcode.com/problems/linked-list-cycle/

// Given head, the head of a linked list, determine
// if the linked list has a cycle in it.

// There is a cycle in a linked list if there is
// some node in the list that can be reached again
// by continuously following the next pointer.
// Internally, pos is used to denote the index of
// the node that tail's next pointer is connected to.
// Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked
// list. Otherwise, return false.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Sol For Leetcode
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

// For VSCode
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