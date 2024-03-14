#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> arr;
        arr[0] = 1;
        int sum = 0;
        int total = 0;

        for (int x : nums)
        {
            sum += x;
            if (arr.find(sum - goal) != arr.end())
            {
                total += arr[sum - goal];
            }
            arr[sum]++;
        }

        return total;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{1, 0, 1, 0, 1};
    int n = 2;
    int result = o1.numSubarraysWithSum(nums, n);
    cout << "Number is Palindromic : " << result << endl;
    return 0;
}