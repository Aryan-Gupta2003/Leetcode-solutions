#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        while (i < n1 && j < n2)
        {
            if (nums1[i] == nums2[j])
                return nums1[i];
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return -1;
    }
};

int main()
{
    Solution o1;
    vector<int> nums1{1, 2, 3, 3, 4};
    vector<int> nums2{2, 4, 6};
    int result = o1.getCommon(nums1, nums2);
    cout << "Minimum Common Value : " << result << endl;
    return 0;
}