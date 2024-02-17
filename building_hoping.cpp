// Leetcode problem statement link
// https://leetcode.com/problems/furthest-building-you-can-reach/

// Given an integer array heights representing the
// heights of buildings, some bricks, and some ladders.

// You start your journey from building 0 and move to
// the next building by possibly using bricks or ladders.

// While moving from building i to building i+1 (0-indexed):
// If the current building's height is greater than or equal to
// the next building's height, you do not need a ladder or bricks.

// If the current building's height is less than the next building's
// height, you can either use one ladder or (h[i+1] - h[i]) bricks.

// Return the furthest building index (0-indexed) you can reach
// if you use the given ladders and bricks optimally.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> p;

        for (int i = 0; i < heights.size() - 1; i++)
        {
            int d = heights[i + 1] - heights[i];
            if (d > 0)
            {
                p.push(d);
                if (p.size() > ladders)
                {
                    bricks -= p.top();
                    p.pop();
                }
                if (bricks < 0)
                    return i;
            }
        }

        return heights.size() - 1;
    }
};

// For VSCode
int main()
{
    vector<int> heigths{4, 12, 2, 7, 3, 18, 20, 3, 19};
    int bricks = 10, ladders = 2;
    Solution o1;
    cout << "Heigths of Building's : ";
    for (auto x : heigths)
    {
        cout << x << " ";
    }
    cout << endl;
    int result = o1.furthestBuilding(heigths, bricks, ladders);
    cout << "Further most Building at which we can go : " << result << endl;
    return 0;
}