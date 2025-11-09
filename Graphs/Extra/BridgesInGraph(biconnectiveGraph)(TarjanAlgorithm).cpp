#include <bits/stdc++.h>
using namespace std;

//can be used to detect biconnective graph
//if broken down into components by deleting an edge then biconnective

void DFS(vector<vector<int>> &adjList,int node,int &time,vector<vector<int>> &ans,vector<bool> &visited,vector<int> &lowTime,vector<int> &discoveryTime,int parent)
{
    visited[node]=true;
    discoveryTime[node]=time++;
    lowTime[node]=discoveryTime[node];
    for(int &x:adjList[node])
    {
        if(!visited[x])
            DFS(adjList,x,time,ans,visited,lowTime,discoveryTime,node);
        //take low time from all adjacent nodes except parent
        if(x!=parent)
            lowTime[node]=min(lowTime[node],lowTime[x]);
        if(discoveryTime[node]<lowTime[x])
            ans.push_back({node,x});        
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
{
    vector<vector<int>> adjList(n);
    for(int i=0;i<connections.size();i++)
    {
        adjList[connections[i][0]].push_back(connections[i][1]);
        adjList[connections[i][1]].push_back(connections[i][0]);
    }
    int time=0;
    vector<int> arrivalTime(n,-1);
    vector<int> lowTime(n,-1);
    vector<bool> visited(n,false);
    vector<vector<int>> bridges;
    for(int i=0;i<n;i++)
        if(!visited[i])
            DFS(adjList,i,time,bridges,visited,lowTime,arrivalTime,-1);

    return bridges;
}

int main()
{

}