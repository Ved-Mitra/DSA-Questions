#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads)
{
    vector<vector<pair<int,int>>> adjList(n);
    for(int i=0;i<roads.size();i++)
    {
        adjList[roads[i][0]].push_back({roads[i][1],roads[i][2]});
        adjList[roads[i][1]].push_back({roads[i][0],roads[i][2]});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    vector<int> dist(n,INT_MAX);
    unordered_map<int,int> cnt;
    while(!pq.empty())
    {
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        for(auto &x:adjList[node])
        {
            if(dist[x.first]> d + x.second)
            {
                dist[x.first]=d + x.second;
                pq.push({dist[x.first],x.first});
            }
            if(x.first==n-1)
                cnt[dist[x.first]]++;
        }
    }
    return cnt[dist[n-1]];
}




int main()
{

}