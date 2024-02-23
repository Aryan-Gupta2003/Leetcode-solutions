#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long long y = 0, c = 10, i = 1;
        if (x < 0)
        {
            i = -1;
            x = x * i;
        }
        while (x > 0)
        {
            y = y * c + (x % 10);
            if (y > INT_MAX)
                return 0;
            x = int(x / 10);
        }
        return y * i;
    }
};

int main()
{
    Solution o1;
    int n = -123;
    int result = o1.reverse(n);
    cout << "Number : " << n << endl;
    cout << "Reverse : " << result << endl;
    return 0;
}