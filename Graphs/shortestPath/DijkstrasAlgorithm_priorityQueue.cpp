#include <bits/stdc++.h>
using namespace std;

//disktra not valid for negative weight and negative cycle
//as in negative weight it falls in infinite loop
//TC - O(E * log V)

vector<int> dijsktraPQ(vector<vector<pair<int,int>>> &adjList,int src)
{
    int n=adjList.size();
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        int dNode=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto &[x,d]:adjList[node])
        {
            if(dist[x]>d+dNode)
            {
                dist[x]=d+dNode;
                pq.push({dist[x],x});
            }
        }
    }
    return dist;
}



int main()
{
    
}