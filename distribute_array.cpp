#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int n1 = 0, n2 = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            if (arr1[n1] > arr2[n2])
            {
                arr1.push_back(nums[i]);
                n1 += 1;
            }
            else
            {
                arr2.push_back(nums[i]);
                n2 += 1;
            }
        }
        for (int i = 0; i < arr2.size(); i++)
        {
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{5, 4, 3, 8, 7, 1, 2, 6, 9};
    vector<int> result = o1.resultArray(nums);
    cout << "Merged array : ";
    for (auto x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}