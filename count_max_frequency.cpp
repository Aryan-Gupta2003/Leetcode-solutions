#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        vector<int> arr;
        set<int> a(nums.begin(), nums.end());
        for (auto it : a)
        {
            int c = count(nums.begin(), nums.end(), it);
            arr.push_back(c);
        }
        int max_count = *max_element(arr.begin(), arr.end());
        int c = max_count * count(arr.begin(), arr.end(), max_count);

        return c;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{10, 12, 11, 9, 6, 19, 11};
    int result = o1.maxFrequencyElements(nums);
    cout << "Count Elements With Maximum Frequency : " << result << endl;
    return 0;
}