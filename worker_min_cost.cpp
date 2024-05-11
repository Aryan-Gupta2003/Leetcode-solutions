// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

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
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        vector<pair<double, int>> ratio;
        int n = quality.size();

        for (int i = 0; i < n; i++)
        {
            ratio.emplace_back(static_cast<double>(wage[i]) / quality[i], i);
        }

        sort(ratio.begin(), ratio.end());
        priority_queue<int> maxHeap;
        int qualitySum = 0;
        double maxRate = 0.0;

        for (int i = 0; i < k; i++)
        {
            qualitySum += quality[ratio[i].second];
            maxRate = max(maxRate, ratio[i].first);
            maxHeap.push(quality[ratio[i].second]);
        }

        double res = maxRate * qualitySum;
        for (int i = k; i < n; ++i)
        {
            maxRate = max(maxRate, ratio[i].first);
            qualitySum -= maxHeap.top();
            maxHeap.pop();
            qualitySum += quality[ratio[i].second];
            maxHeap.push(quality[ratio[i].second]);
            res = min(res, maxRate * qualitySum);
        }
        return res;
    }
};

int main()
{
    Solution o1;
    vector<int> quality{3, 1, 10, 10, 1};
    vector<int> wage{4, 8, 2, 2, 7};
    int k = 3;
    double result = o1.mincostToHireWorkers(quality, wage, k);
    cout << "Minimum Cost to Hire K Workers : " << result << endl;
    return 0;
}