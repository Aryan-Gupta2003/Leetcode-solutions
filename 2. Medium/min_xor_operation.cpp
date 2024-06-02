// Leetcode problem statement link
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

// You are given a 0-indexed integer array nums
// and a positive integer k.

// You can apply the following operation on the
// array any number of times:
// Choose any element of the array and flip a bit
// in its binary representation. Flipping a bit
// means changing a 0 to 1 or vice versa.
// Return the minimum number of operations required
// to make the bitwise XOR of all elements of the
// final array equal to k.

// Note that you can flip leading zero bits in the
// binary representation of elements. For example,
// for the number (101)2 you can flip the fourth
// bit and obtain (1101)2.

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
    int minOperations(vector<int> &nums, int k)
    {
        int ans = 0;
        for (int n : nums)
        {
            ans = ans ^ n;
        }
        int c = 0;
        while (k || ans)
        {
            if ((k % 2) != (ans % 2))
            {
                c++;
            }
            k /= 2;
            ans /= 2;
        }
        return c;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> nums{2, 1, 3, 4};
    int k = 1;
    int result = o1.minOperations(nums, k);
    cout << "Minimum no. of operations to make array XOR equal to K : "
         << result << endl;
    return 0;
}