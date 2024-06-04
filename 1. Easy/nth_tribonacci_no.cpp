// Leetcode problem statement link
// https://leetcode.com/problems/n-th-tribonacci-number/

// The Tribonacci sequence Tn is defined as follows:
// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
// Given n, return the value of Tn.

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
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        else if (n == 1 || n == 2)
            return 1;
        int a0 = 0, a1 = 1, a2 = 1, i = 3, a3;
        while (i <= n)
        {
            a3 = a0 + a1 + a2;
            a0 = a1;
            a1 = a2;
            a2 = a3;
            i++;
        }
        return a3;
    }
};

// For VSCode
int main()
{
    Solution o1;
    int n = 25;
    int result = o1.tribonacci(n);
    cout << "N-th Tribonacci Number : " << result << endl;
    return 0;
}