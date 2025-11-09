#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adjList(n + 1);
    for (int i = 0; i < times.size(); i++)
        adjList[times[i][0]].push_back({times[i][1], times[i][2]});
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dNode = pq.top().first;
        pq.pop();
        for (auto &[x, d] : adjList[node])
        {
            if (dist[x] > dNode + d)
            {
                dist[x] = dNode + d;
                pq.push({dist[x], x});
            }
        }
    }
    int time = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
            return -1;
        time = max(time, dist[i]);
    }
    return time;
}

int main()
{
    
}