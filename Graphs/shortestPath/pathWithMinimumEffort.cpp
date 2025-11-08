#include <bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>> &heights)
{
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[0][0] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int row[] = {-1, 0, +1, 0};
    int col[] = {0, +1, 0, -1};
    pq.push({0, {0, 0}});
    while (!pq.empty())
    {
        int dNode = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = r + row[i];
            int y = c + col[i];
            if (x >= 0 && x < m && y >= 0 && y < n && dist[x][y] > max(dNode, abs(heights[x][y] - heights[r][c])))
            {
                dist[x][y] = max(dNode, abs(heights[x][y] - heights[r][c]));
                pq.push({dist[x][y], {x, y}});
            }
        }
    }
    return dist[m - 1][n - 1];
}

int main()
{
}