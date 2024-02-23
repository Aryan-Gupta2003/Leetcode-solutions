#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; ++i)
        {
            vector<int> temp = dist;
            for (const auto &flight : flights)
            {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];
                if (dist[from] != INT_MAX && dist[from] + price < temp[to])
                {
                    temp[to] = dist[from] + price;
                }
            }
            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main()
{
    Solution o1;
    int n = 4, src = 0, dst = 3, k = 1;
    vector<vector<int>> flights{{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int result = o1.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest Price : " << result << endl;

    return 0;
}