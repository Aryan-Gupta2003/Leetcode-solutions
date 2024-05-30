// Leetcode problem statement link
// https://leetcode.com/problems/delete-node-in-a-linked-list/

// There is a singly-linked list head and
// we want to delete a node node in it.

// You are given the node to be deleted node. You
// will not be given access to the first node of head.

// All the values of the linked list are unique,
// and it is guaranteed that the given node node
// is not the last node in the linked list.

// Delete the given node. Note that by deleting
// the node, we do not mean removing it from
// memory. We mean:

// The value of the given node should not exist
// in the linked list.
// The number of nodes in the linked list should
// decrease by one.
// All the values before node should be in the same order.
// All the values after node should be in the same order.

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
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
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

    cout << "Before deletion: ";
    ListNode *curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    o1.deleteNode(head->next->next);

    cout << "After deletion: ";
    curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        ListNode *temp = curr;
        curr = curr->next;
        delete temp; // Cleanup
    }
    cout << endl;
    return 0;
}