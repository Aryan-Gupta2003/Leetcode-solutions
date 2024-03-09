// Leetcode problem statement link
// https://leetcode.com/problems/middle-of-the-linked-list/

// Given the head of a singly linked list, return the
// middle node of the linked list.

// If there are two middle nodes, return the
// second middle node.

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

// Sol For Leetcode
class Solution
{
public:
    int length(ListNode *head)
    {
        vector<int> arr;
        ListNode *p = head;
        while (p != nullptr)
        {
            arr.push_back(p->val);
            p = p->next;
        }
        return int(arr.size() / 2);
    }
    ListNode *middleNode(ListNode *head)
    {
        int l = length(head);
        ListNode *q = head;
        while (l--)
        {
            q = q->next;
        }
        return q;
    }
};

// For VSCode
int main()
{
    Solution o1;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *r = o1.middleNode(head);
    cout << "List from middle node to the end: ";
    while (r != nullptr)
    {
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;

    return 0;
}