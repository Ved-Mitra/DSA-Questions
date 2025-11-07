#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes_BFS(vector<vector<int>>& graph)
{
    //reverse edges , then do topological sort
    int n=graph.size();
    vector<int> outDegree(graph.size(),0);
    vector<vector<int>> reverseAdjList(n);
    for(int i=0;i<graph.size();i++)
    {
        outDegree[i]+=graph[i].size();
        for(int j=0;j<graph[i].size();j++)
            reverseAdjList[graph[i][j]].push_back(i);
    }
    queue<int> q;
    for(int i=0;i<n;i++)
        if(outDegree[i]==0)
            q.push(i);
    vector<int> ans;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int &x:reverseAdjList[node])
        {
            outDegree[x]--;
            if(outDegree[x]==0)
                q.push(x);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;    
}



bool DFSHelper(vector<vector<int>> &graph,vector<bool> &check,vector<bool> &visited,vector<bool> &pathVisited,int node)
{
    visited[node]=true;
    pathVisited[node]=true;
    check[node]=false;
    for(int &x:graph[node])
    {
        if(!visited[x])
        {
            if(DFSHelper(graph,check,visited,pathVisited,x))
            {
                check[node]=0;
                return true;
            }
        }
        else if(pathVisited[x])
        {
            check[node]=0;
            return true;
        }
    }
    check[node]=true;
    pathVisited[node]=false;
    return false;
}
vector<int> eventualSafeNodes_DFS(vector<vector<int>>& graph)
{
    vector<int> ans;
    int n=graph.size();
    vector<bool> visited(n,false);
    vector<bool> pathVisited(n,false);
    vector<bool> check(n,false);
    for(int i=0;i<n;i++)
        if(!visited[i])
            DFSHelper(graph,check,visited,pathVisited,i);
    for(int i=0;i<n;i++)
        if(check[i]==1)
            ans.push_back(i);
    return ans;
}




int main()
{

}