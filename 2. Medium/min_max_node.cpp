// Leetcode problem statement link
// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

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
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> arr;
        vector<int> ans;
        ListNode *p = head;
        int temp1 = p->val;
        int x, temp2, i = 1;
        p = p->next;
        while (p->next != nullptr)
        {
            x = p->val;
            temp2 = p->next->val;
            if ((x > temp1 && x > temp2) || (x < temp1 && x < temp2))
            {
                arr.push_back(i);
            }
            i++;
            p = p->next;
            temp1 = x;
        }
        int n = arr.size();
        if (n > 1)
        {
            int m = abs(arr[0] - arr[1]);
            sort(arr.begin(), arr.end());
            for (int j = 1; j < n - 1; j++)
            {
                if (m > abs(arr[j] - arr[j + 1]))
                {
                    m = abs(arr[j] - arr[j + 1]);
                }
            }
            ans.push_back(m);
            ans.push_back(arr.back() - arr[0]);
        }
        else
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next->next = new ListNode(7);

    Solution o1;
    vector<int> result = o1.nodesBetweenCriticalPoints(head);
    cout << "Minimum distance: " << result[0] << endl;
    cout << "Maximum distance: " << result[1] << endl;
    return 0;
}