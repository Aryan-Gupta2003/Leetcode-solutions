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
    bool isPalindrome(ListNode *head)
    {
        vector<int> arr;
        while (head)
        {
            arr.push_back(head->val);
            head = head->next;
        }

        int start = 0, end = arr.size() - 1;
        while (start < end && arr[start] == arr[end])
        {
            start++;
            end--;
        }
        return (start >= end ? true : false);
    }
};

int main()
{
    Solution o1;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    bool r = o1.isPalindrome(head);
    cout << "Link List is in Pallindrome : " << (r == 1 ? "True" : "False")
         << endl;

    return 0;
}