// Leetcode problem statement link
// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

// There are n workers. You are given two integer
// arrays quality and wage where quality[i] is the
// quality of the ith worker and wage[i] is the
// minimum wage expectation for the ith worker.

// We want to hire exactly k workers to form a
// paid group. To hire a group of k workers, we
// must pay them according to the following rules:

// Every worker in the paid group must be paid at
// least their minimum wage expectation. In the
// group, each worker's pay must be directly
// proportional to their quality. This means if a
// worker’s quality is double that of another worker
// in the group, then they must be paid twice as much
// as the other worker.
// Given the integer k, return the least amount of
// money needed to form a paid group satisfying the
// above conditions. Answers within 10-5 of the
// actual answer will be accepted.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
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

// For VSCode
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