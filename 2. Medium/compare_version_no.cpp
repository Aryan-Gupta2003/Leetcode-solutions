// Leetcode problem statement link
// https://leetcode.com/problems/compare-version-numbers/

// Given two version strings, version1 and
// version2, compare them. A version string
// consists of revisions separated by dots
// '.'. The value of the revision is its
// integer conversion ignoring leading zeros.

// To compare version strings, compare their
// revision values in left-to-right order.
// If one of the version strings has fewer
// revisions, treat the missing revision
// values as 0.

// Return the following:
// If version1 < version2, return -1.
// If version1 > version2, return 1.
// Otherwise, return 0.

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
    int compareVersion(string v1, string v2)
    {
        const int n1 = v1.size(), n2 = v2.size();
        int x1 = 0, x2 = 0;
        for (int i = 0, j = 0; i < n1 || j < n2; i++, j++)
        {
            while (i < n1 && v1[i] != '.')
            {
                x1 = 10 * x1 + (v1[i++] - '0');
            }
            while (j < n2 && v2[j] != '.')
            {
                x2 = 10 * x2 + (v2[j++] - '0');
            }
            if (x1 < x2)
                return -1;
            else if (x1 > x2)
                return 1;
            x1 = 0;
            x2 = 0;
        }
        return 0;
    }
};

// For VSCode
int main()
{
    Solution o1;
    string v1 = "1.01", v2 = "1.001";
    int result = o1.compareVersion(v1, v2);
    cout << "Compare Version Numbers : " << result << endl;
    return 0;
}