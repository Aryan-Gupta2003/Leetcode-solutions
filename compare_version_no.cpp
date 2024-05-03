// https://leetcode.com/problems/compare-version-numbers/

#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    Solution o1;
    string v1 = "1.01", v2 = "1.001";
    int result = o1.compareVersion(v1, v2);
    cout << "Compare Version Numbers : " << result << endl;
    return 0;
}