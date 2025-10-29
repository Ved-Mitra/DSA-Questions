#include <bits/stdc++.h>
using namespace std;

bool BFS(vector<vector<int>> &adjList,int n,vector<bool> &visited,int i)
{
    queue<pair<int,int>> q;//parent-child
    q.push({i,i});
    visited[i]=true;
    while(!q.empty())
    {
        int l=q.size();
        for(int i=0;i<l;i++)
        {
            pair<int,int> x=q.front();
            q.pop();
            for(int &node:adjList[x.second])
            {
                if(visited[node] && node!=x.first)
                    return true;
                if(!visited[node])
                {
                    q.push({x.second,node});
                    visited[node]=true;
                }
            }
        }
    }
    return false;
}
bool detectCycle_in_UndirectedGraph_BFS(vector<vector<int>> &adjList,int n)
{
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++)
        if(!visited[i])
            if(BFS(adjList,n,visited,i))
                return true;
}


bool DFS(vector<vector<int>> &adjList,vector<bool> &visited,int n,int node,int parent)
{
    if(node>n)
        return false;
    visited[node]=true;
    for(int &x:adjList[node])
    {
        if(visited[x] && x!=parent)
            return true;
        if(!visited[x] && DFS(adjList,visited,n,x,node))
            return true;
    }
    return false;
}
bool detectCycle_in_UndirectedGraph_DFS(vector<vector<int>> &adjList,int n)
{
    vector<bool>visited(n+1,false);
    for(int i=1;i<=n;i++)
        if(!visited[i])
            if(DFS(adjList,visited,n,i,-1))
            {
                return true;
            }
    return false;
}


int main()
{
    
}