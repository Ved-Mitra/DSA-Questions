#include <bits/stdc++.h>
using namespace std;

vector<int>shortesPath(int n,int m,vector<vector<int>> &edges,int src)
{
    vector<vector<int>> adjList;
    for(int i=0;i<edges.size();i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    //take the nodes out of the stack and relax the edges
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto &x:adjList[node])
        {
            if(dist[x]>1+dist[node])
            {
                dist[x]=1+dist[node];
                q.push(x);
            }
        }
    }
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++)
        if(dist[i]!=-1)
            ans[i]=dist[i];
    return ans;
}


int main ()
{

}