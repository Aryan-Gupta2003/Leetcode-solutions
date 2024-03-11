#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        sort(capacity.begin(), capacity.end());
        int sum = 0;
        for (int i = 0; i < apple.size(); i++)
        {
            sum += apple[i];
        }
        int c = 0;
        for (int i = (capacity.size() - 1); i >= 0; i--)
        {
            sum = sum - capacity[i];
            c += 1;
            if (sum <= 0)
                return c;
        }
        return c;
    }
};

int main()
{
    Solution o1;
    vector<int> apple{1, 3, 2, 4};
    vector<int> capacity{4, 3, 2, 1, 5, 6};
    int result = o1.minimumBoxes(apple, capacity);
    cout << "Minimum number of boxes neede to place apple : "
         << result << endl;
    return 0;
}