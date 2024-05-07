// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/

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
    ListNode *doubleIt(ListNode *head)
    {
        ListNode *reversedList = reverseList(head);
        int carry = 0;
        ListNode *current = reversedList, *previous = nullptr;
        while (current != nullptr)
        {
            int newValue = current->val * 2 + carry;
            current->val = newValue % 10;
            if (newValue > 9)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            previous = current;
            current = current->next;
        }
        if (carry != 0)
        {
            ListNode *extraNode = new ListNode(carry);
            previous->next = extraNode;
        }
        ListNode *result = reverseList(reversedList);
        return result;
    }

    ListNode *reverseList(ListNode *node)
    {
        ListNode *previous = nullptr, *current = node, *nextNode;
        while (current != nullptr)
        {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        return previous;
    }
};

int main()
{
    Solution o1;
    ListNode *head = new ListNode(9);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);

    ListNode *result = o1.doubleIt(head);

    ListNode *curr = result;
    string sep = "";
    cout << "Doubly Linked List : [";
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