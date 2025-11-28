#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
{
    vector<vector<pair<int,int>>> adjList(n);
    for(int i=0;i<flights.size();i++)
    {
        adjList[flights[i][0]].push_back({flights[i][1],flights[i][2]});
    }

    queue<pair<pair<int,int>,int>> q;
    q.push({{0,src},0});
    vector<int> dist(n,INT_MAX);

    while(!q.empty())
    {
        int node=q.front().first.second;
        int d=q.front().first.first;
        int stop=q.front().second;
        q.pop();
        if(stop>k)
            break;
        for(auto &x:adjList[node])
            if(dist[x.first]>d+x.second)
            {
                dist[x.first]=d+x.second;
                q.push({{dist[x.first],x.first},stop+1});
            }
    }
    if(dist[dst]==INT_MAX)
        return -1;
    return dist[dst];
}



int main()
{

}