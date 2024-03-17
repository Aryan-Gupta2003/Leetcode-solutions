#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int pow = 0;
    if (pow < a[n - 1])
        pow += a[n - 1];
    if (pow < (a[n - 2] + pow))
        pow += a[n - 2];

    cout << pow;

    return 0;
}