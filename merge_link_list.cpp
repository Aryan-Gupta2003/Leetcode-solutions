// Leetcode problem statement link
// https://leetcode.com/problems/merge-in-between-linked-lists/

// You are given two linked lists: list1 and list2 of sizes n
// and m respectively.

// Remove list1's nodes from the ath node to the bth node,
// and put list2 in their place.

// The blue edges and nodes in the following figure
// indicate the result:

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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *head1 = list1;
        ListNode *head2 = list1;
        int c = 0;
        while (c < a - 1)
        {
            head1 = head1->next;
            head2 = head2->next;
            c++;
        }
        while (c <= b)
        {
            head2 = head2->next;
            c++;
        }
        head1->next = list2;
        while (head1->next != nullptr)
        {
            head1 = head1->next;
        }

        head1->next = head2;
        return list1;
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

    ListNode *head2 = new ListNode(10000);
    head2->next = new ListNode(10001);
    head2->next->next = new ListNode(10002);

    int a = 2, b = 3;

    ListNode *r = o1.mergeInBetween(head, a, b, head2);
    cout << "List after maerging both list: ";
    while (r != nullptr)
    {
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;

    return 0;
}