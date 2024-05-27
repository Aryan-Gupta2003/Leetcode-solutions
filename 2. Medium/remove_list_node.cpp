// Leetcode problem statement link
// https://leetcode.com/problems/remove-nodes-from-linked-list/

// You are given the head of a linked list.

// Remove every node which has a node with a
// greater value anywhere to the right side of it.

// Return the head of the modified linked list.

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
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    ListNode *removeNodes(ListNode *head)
    {
        ListNode *cur = head;
        stack<ListNode *> stack;
        while (cur != nullptr)
        {
            while (!stack.empty() && stack.top()->val < cur->val)
            {
                stack.pop();
            }
            stack.push(cur);
            cur = cur->next;
        }
        ListNode *nxt = nullptr;
        while (!stack.empty())
        {
            cur = stack.top();
            stack.pop();
            cur->next = nxt;
            nxt = cur;
        }
        return cur;
    }
};

// For VSCode
int main()
{
    Solution o1;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(16);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    ListNode *newHead = o1.removeNodes(head);

    ListNode *curr = newHead;
    string sep = "";
    cout << "Modified Linked List : [";
    while (curr != nullptr)
    {
        cout << sep << curr->val;
        sep = ", ";
        ListNode *temp = curr;
        curr = curr->next;
        delete temp;
    }
    cout << "]" << endl;
    return 0;
}