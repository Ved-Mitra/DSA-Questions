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

    int mod=1e9 + 7;
    vector<int> ways(n,0);
    ways[0]=1;
    vector<long long> dist(n,LONG_LONG_MAX);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        int Ndist=pq.top().first;
        pq.pop();
        if(Ndist>dist[u])
            continue;
        for(auto x:adjList[u])
        {
            int v=x.first;
            long long t=x.second;
            if(dist[u]+t<dist[v])
            {
                dist[v]=dist[u]+t;
                ways[v]=(ways[u]);
                pq.push({dist[v],v});
            }
            else if(dist[u]+t==dist[v])
            {
                ways[v]=(ways[v]+ways[u])%mod;
            }
        }
    }
    return ways[n-1];
}




int main()
{

}