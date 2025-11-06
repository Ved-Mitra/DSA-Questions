#include <bits/stdc++.h>
using namespace std;


bool DFS(vector<vector<int>> &adjList,int node,vector<bool> &visited,vector<bool> &pathVisted)
{
    visited[node]=true;
    pathVisted[node]=true;
    for(int &x:adjList[node])
    {
        if(!visited[x])
            if(DFS(adjList,x,visited,pathVisted))
                return true;
        if(visited[x] && pathVisted[x])
            return true;
    }
    pathVisted[node]=false;
    return false;
}
bool detectCycleInDirectedGraph(vector<vector<int>> &adjList)
{
    int n=adjList.size();
    vector<bool> visited(n,false);
    vector<bool> pathVisited(n,false);

    for(int i=0;i<n;i++)
        if(!visited[i])
            if(DFS(adjList,i,visited,pathVisited))
                return true;
    return false;
}


int main()
{

}