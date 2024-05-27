// Leetcode problem statement link
// https://leetcode.com/problems/k-th-smallest-prime-fraction/

// You are given a sorted integer array arr
// containing 1 and prime numbers, where all
// the integers of arr are unique. You are
// also given an integer k.

// For every i and j where 0 <= i < j < arr.length,
// we consider the fraction arr[i] / arr[j].

// Return the kth smallest fraction considered.
// Return your answer as an array of integers
// of size 2, where answer[0] == arr[i] and
// answer[1] == arr[j].

#include <bits/stdc++.h>
using namespace std;

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
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        int n = arr.size();
        double low = 0, high = 1;
        vector<int> ans(2);

        while (low < high)
        {
            double mid = (low + high) / 2;
            int count = 0;
            pair<int, int> maxFraction = {0, 1};
            for (int i = 0, j = 1; i < n - 1; i++)
            {
                while (j < n && arr[i] >= arr[j] * mid)
                    j++;
                count += n - j;

                if (j < n && maxFraction.first * arr[j] < maxFraction.second * arr[i])
                {
                    maxFraction = {arr[i], arr[j]};
                }
            }

            if (count == k)
            {
                ans[0] = maxFraction.first;
                ans[1] = maxFraction.second;
                break;
            }
            else if (count < k)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }

        return ans;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> arr{1, 2, 3, 5};
    int k = 3;
    string sep = "";
    vector<int> result = o1.kthSmallestPrimeFraction(arr, k);
    cout << "K-th Smallest Prime Fraction : [";
    for (int x : result)
    {
        cout << sep << x;
        sep = ", ";
    }
    cout << "]" << endl;
    return 0;
}