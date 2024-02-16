#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> m;
        vector<int> nums3;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for (int i = 0; i < n1; i++)
            m[nums1[i]]++;
        for (int i = 0; i < n2; i++)
            m[nums2[i]]++;
        for (auto i : m)
        {
            for (int j = 0; j < i.second; j++)
                nums3.push_back(i.first);
        }
        int mid = (n1 + n2) / 2;
        cout << "Merged Sorted Array : ";
        for (auto x : nums3)
        {
            cout << x << " ";
        }
        cout << endl;
        if ((n1 + n2) % 2 == 0)
            return (float(nums3[mid] + nums3[mid - 1]) / 2);
        else
            return float(nums3[mid]);
    }
};

int main()
{
    Solution o1;
    vector<int> nums1{1, 3, 5};
    vector<int> nums2{2, 4, 6};
    cout << "Array 1 : ";
    for (auto x : nums1)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << "Array 2 : ";
    for (auto x : nums2)
    {
        cout << x << " ";
    }
    cout << endl;

    int result = o1.findMedianSortedArrays(nums1, nums2);
    cout << "Median : " << result << endl;
    return 0;
}