// Leetcode problem statement link
// https://leetcode.com/problems/reverse-linked-list/

// Given the head of a singly linked list, reverse
// the list, and return the reversed list.

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *next = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
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
    head->next->next->next->next->next = new ListNode(6);

    ListNode *r = o1.reverseList(head);
    cout << "Reverse Link List : ";
    while (r != nullptr)
    {
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;
    return 0;
}