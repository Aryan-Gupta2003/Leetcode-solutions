// Leetcode problem statement link
// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

// Given an array of integers arr.

// We want to select three indices i, j and
// k where (0 <= i < j <= k < arr.length).

// Let's define a and b as follows:

// a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
// b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
// Note that ^ denotes the bitwise-xor operation.

// Return the number of triplets
// (i, j and k) Where a == b.

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
    int countTriplets(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        for (int i = 0; i < n; ++i)
        {
            for (int k = i + 1; k < n; ++k)
            {
                if (prefix[i] == prefix[k + 1])
                {
                    count += (k - i);
                }
            }
        }
        return count;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> arr{2, 3, 1, 6, 7};
    int result = o1.countTriplets(arr);
    cout << "Number of triplets : " << result << endl;
    return 0;
}