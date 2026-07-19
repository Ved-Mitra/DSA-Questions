#include <bits/stdc++.h>
using namespace std;


bool DFS(vector<vector<int>> &adjList,int node,vector<bool> &visited,vector<bool> &pathVisted)
{
    visited[node]=true;
    pathVisted[node]=true;
    for(int &x:adjList[node])
    {
        if(visited[x] && pathVisted[x])
                return true;
        if(!visited[x])
            if(DFS(adjList,x,visited,pathVisted))
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

bool detectCycleInDirectedGraph_BFS(vector<vector<int>> &adjList){
    int n=adjList.size();
    vector<int> in_degree(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<adjList[i].size();j++){
            in_degree[adjList[i][j]]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }
    int visited=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        visited++;
        for(int x:adjList[node]){
            in_degree[x]--;
            if(in_degree[x]==0){
                q.push(x);
            }
        }
    }
    return visited!=n;
}


int main()
{

}
