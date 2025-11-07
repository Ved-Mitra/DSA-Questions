#include <bits/stdc++.h>
using namespace std;


void DFS(vector<vector<pair<int,int>>> &adjList,vector<bool> &visited,stack<int> &st,int node)
{
    visited[node]=true;
    for(auto &x:adjList[node])
        if(!visited[x.first])
            DFS(adjList,visited,st,x.first);
    st.push(node);
}
vector<int>shortesPath(int n,int m,vector<vector<int>> &edges,int src)
{
    vector<vector<pair<int,int>>> adjList(n);
    for(int i=0;i<edges.size();i++)
        adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    //1. do a Topo sort
    vector<bool> visited(n,false);
    stack<int> st;
    for(int i=0;i<n;i++)
        if(!visited[i])
            DFS(adjList,visited,st,i);
    //take the nodes out of the stack and relax the edges
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    while(!st.empty())
    {
        int node=st.top();
        int dNode=dist[node];
        st.pop();
        if(dNode!=INT_MAX)
        {
            for(int i=0;i<adjList[node].size();i++)
            {
                int x=adjList[node][i].first;
                int d=adjList[node][i].second;
                dist[x]=min(dist[x],d+dNode);
            }
        }
    }
    return dist;
}


int main ()
{

}