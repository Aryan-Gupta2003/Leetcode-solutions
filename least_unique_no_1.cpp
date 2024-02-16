// Leetcode problem statement link
// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

// Given an array of integers arr and an integer k.
// Find the least number of unique integers after
// removing exactly k elements.

#include <bits/stdc++.h>
using namespace std;

// Sol for Leetcode
class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        set<int> s(arr.begin(), arr.end());

        vector<int> c;
        for (auto x : s)
        {
            int n = count(arr.begin(), arr.end(), x);
            c.push_back(n);
        }

        sort(c.begin(), c.end());

        for (int i = 0; i < c.size(); i++)
        {
            k -= c[i];
            if (k == 0)
            {
                c[i] = 0;
                break;
            }
            else if (k > 0)
            {
                c[i] = 0;
            }
            else
            {
                c[i] -= k;
                break;
            }
        }

        int q = 0;
        for (int i = 0; i < c.size(); i++)
        {
            if (c[i] > 0)
                q += 1;
        }
        return q;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> arr{5, 5, 4};
    int k = 1;
    int result = o1.findLeastNumOfUniqueInts(arr, k);
    cout << "Array : ";
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Least no of unique elements after " << k
         << " removals : " << result << endl;
    return 0;
}