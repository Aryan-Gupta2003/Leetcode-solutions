#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        int i = 1, j = n;
        int prefix = i, suffix = j;
        while (i <= j)
        {
            if ((i == j) && (prefix == suffix))
                return i;
            if (prefix <= suffix)
            {
                i++;
                prefix += i;
            }
            else
            {
                j--;
                suffix += j;
            }
        }
        return -1;
    }
};

int main()
{
    Solution o1;
    int n = 8;
    int result = o1.pivotInteger(n);
    cout << "Pivot Integer : " << result << endl;
    return 0;
}