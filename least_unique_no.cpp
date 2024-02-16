// Leetcode problem statement link
// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

// Given an array of integers arr and an integer k.
// Find the least number of unique integers after
// removing exactly k elements.

#include <bits/stdc++.h>
using namespace std;

// Sol for Leetcode
class Solution1
{
public:
    int findLeastNumOfUniqueInts1(vector<int> &arr, int k)
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

class Solution2
{
public:
    int findLeastNumOfUniqueInts2(vector<int> &arr, int k)
    {
        unordered_map<int, int> map;
        for (int i : arr)
        {
            map[i]++;
        }

        int n = arr.size();
        vector<int> c(n + 1, 0);
        for (auto it : map)
        {
            c[it.second]++;
        }

        int r = map.size();
        for (int i = 1; i <= n; i++)
        {
            int num = min(k / i, c[i]);
            k -= (i * num);
            r -= num;
            if (k < i)
            {
                return r;
            }
        }
        return 0;
    }
};

// For VSCode
int main()
{
    Solution1 o1;
    Solution2 o2;
    vector<int> arr{5, 5, 4};
    int k1 = 1, k2 = 3;
    int result1 = o1.findLeastNumOfUniqueInts1(arr, k1);
    int result2 = o2.findLeastNumOfUniqueInts2(arr, k2);
    cout << "Array : ";
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Least no of unique elements after " << k1
         << " removals : " << result1 << endl;
    cout << "Least no of unique elements after " << k2
         << " removals : " << result2 << endl;
    return 0;
}