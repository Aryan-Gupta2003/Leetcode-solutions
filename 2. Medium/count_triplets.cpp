// Leetcode problem statement link
// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

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
    int countTriplets(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        for (int i = 0; i < n; ++i)
        {
            for (int k = i + 1; k < n; ++k)
            {
                if (prefix[i] == prefix[k + 1])
                {
                    count += (k - i);
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution o1;
    vector<int> arr{2, 3, 1, 6, 7};
    int result = o1.countTriplets(arr);
    cout << "Number of triplets : " << result << endl;
    return 0;
}