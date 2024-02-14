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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = 0;
            sum = (l1 != nullptr) ? sum + l1->val : sum;
            sum = (l2 != nullptr) ? sum + l2->val : sum;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;

            sum += carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            tail->next = newNode;
            tail = tail->next;
        }
        ListNode *l3 = head->next;
        delete head;
        return l3;
    }
};

void addNode(ListNode *&head, int val)
{
    ListNode *newNode = new ListNode(val);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        ListNode *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

void displayList(ListNode *head)
{
    ListNode *tail = head;
    while (tail != nullptr)
    {
        cout << tail->val << " ";
        tail = tail->next;
    }
    cout << endl;
}

int main()
{
    Solution o1;
    ListNode *head1 = nullptr, *head2 = nullptr;

    addNode(head1, 3);
    addNode(head1, 6);
    addNode(head1, 4);

    addNode(head2, 4);
    addNode(head2, 7);
    addNode(head2, 9);

    cout << "Linked List 1: ";
    displayList(head1);
    cout << "Linked List 2: ";
    displayList(head2);

    ListNode *head3 = o1.addTwoNumbers(head1, head2);
    cout << "Added Linked List : ";
    displayList(head3);

    return 0;
}