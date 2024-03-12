// Leetcode problem statement link
// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

// Given the head of a linked list, we repeatedly
// delete consecutive sequences of nodes that sum
// to 0 until there are no such sequences.

// After doing so, return the head of the final
// linked list.  You may return any such answer.

// (Note that in the examples below, all sequences
// are serializations of ListNode objects.)

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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode node = ListNode(0, head);
        unordered_map<int, ListNode *> mp;
        int sum = 0;
        for (ListNode *ptr = &node; ptr; ptr = ptr->next)
        {
            sum += (ptr->val);
            mp[sum] = ptr;
        }
        sum = 0;
        for (ListNode *ptr = &node; ptr; ptr = ptr->next)
        {
            sum += (ptr->val);
            ptr->next = mp[sum]->next;
        }
        return node.next;
    }
};

// For VSCode
int main()
{
    Solution o1;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *r = o1.removeZeroSumSublists(head);
    cout << "List from middle node to the end: ";
    while (r != nullptr)
    {
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;
    return 0;
}