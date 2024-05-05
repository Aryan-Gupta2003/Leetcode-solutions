// https://leetcode.com/problems/delete-node-in-a-linked-list/

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