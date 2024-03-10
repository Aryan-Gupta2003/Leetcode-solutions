#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> arr;
        while (i < n1 && j < n2)
        {
            if (nums1[i] == nums2[j])
            {
                arr.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        vector<int>::iterator ip;
        ip = unique(arr.begin(), arr.end());
        arr.resize(distance(arr.begin(), ip));
        return arr;
    }
};

int main()
{
    Solution o1;
    vector<int> nums1{1, 2, 3, 3, 4};
    vector<int> nums2{4, 2, 6};
    vector<int> result = o1.intersection(nums1, nums2);
    cout << "Intersection of Two Arrays : ";
    for (auto x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}