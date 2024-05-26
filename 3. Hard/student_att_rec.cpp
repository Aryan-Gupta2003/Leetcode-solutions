// Leetcode problem statement link
// https://leetcode.com/problems/student-attendance-record-ii/

// An attendance record for a student can be represented
// as a string where each character signifies whether the
// student was absent, late, or present on that day. The
// record only contains the following three characters:
// 'A': Absent.
// 'L': Late.
// 'P': Present.
// Any student is eligible for an attendance award
// if they meet both of the following criteria:

// The student was absent ('A') for strictly fewer than 2 days total.
// The student was never late ('L') for 3 or more consecutive days.
// Given an integer n, return the number of possible attendance
// records of length n that make a student eligible for an attendance
// award. The answer may be very large, so return it modulo 109 + 7

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    const long long mod = 1e9 + 7;
    long long dp[100001][2][3];

    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    long long f(int i, int absent, int late)
    {
        if (absent >= 2 || late >= 3)
            return 0;
        if (i == 0)
            return 1;
        if (dp[i][absent][late] != -1)
            return dp[i][absent][late];

        long long ans = f(i - 1, absent, 0);
        ans += (late < 2 ? f(i - 1, absent, late + 1) : 0);
        ans += (absent == 0 ? f(i - 1, absent + 1, 0) : 0);
        return dp[i][absent][late] = ans % mod;
    }
    int checkRecord(int n)
    {
        fill(&dp[0][0][0], &dp[0][0][0] + (n + 1) * 6, -1);
        return f(n, 0, 0);
    }
};

// For VSCode
int main()
{
    Solution o1;
    int n = 2;
    int result = o1.checkRecord(n);
    cout << "No. of records : " << result << endl;
    return 0;
}