// Leetcode problem statement link
// https://leetcode.com/problems/apple-redistribution-into-boxes/

// You are given an array apple of size n and an
// array capacity of size m.

// There are n packs where the ith pack contains
// apple[i] apples. There are m boxes as well, and
// the ith box has a capacity of capacity[i] apples.

// Return the minimum number of boxes you need to
// select to redistribute these n packs of apples
// into boxes.

// Note that, apples from the same pack can be
// distributed into different boxes.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
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

// For VSCode
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