#include <bits/stdc++.h>
using namespace std;


//ME
bool BFS(vector<vector<int>> &adjList,int i,vector<pair<bool,int>> &visited,int group)
{
    //U -- group=0
    //T -- group=1
    
    queue<pair<int,int>> q; // node -- group
    q.push({i,group});
    visited[i]={true,group};
    while(!q.empty())
    {
        int node=q.front().first;
        int group=q.front().second;
        q.pop();
        //now reversing group for the next nodes found by BFS
        int newGroup= !group;
        for(int &x:adjList[node])
        {
            if(visited[x].first && visited[x].second!=newGroup)
                return false;
            if(!visited[x].first)
            {
                q.push({x,newGroup});
                visited[x]={true,newGroup};
            }
        }
    }
    return true;
}
bool detectBipartite(vector<vector<int>> &adjList,int n)
{
    int n=adjList.size();
    vector<pair<bool,int>> visited(n,pair<bool,int>(false,-1));
    
    for(int i=0;i<n;i++)
        if(!visited[i].first)
            if(!BFS(adjList,i,visited,0))
                return false;
    return true;
}


//STRIVER's
bool BFS_Helper(vector<vector<int>> &adjList,int node,vector<int> &visited)
{
    queue<int> q;
    q.push(node);
    visited[node]=0;
    while(!q.empty())
    {
        int i=q.front();
        q.pop();
        int GroupToBeAssigned=1-visited[i];
        for(int &x:adjList[i])
        {
            if(visited[x]==-1)
            {
                q.push(x);
                visited[x]=GroupToBeAssigned;
            }
            else if(visited[x]==visited[i])
                return false;
        }
    }
    return true;
}
bool DFS_Helper(vector<vector<int>> &adjList,int node,vector<int> &visited,int color)
{
    visited[node]=color;
    for(int &x:adjList[node])
    {
        if(visited[x]==-1)
        {
            visited[x]=!color;
            if(!DFS_Helper(adjList,x,visited,!color))
                return false;
        }
        else if(visited[x]==visited[node])
            return false;
    }
    return true;
}
bool detectBipartite_BFS_OR_DFS(vector<vector<int>> &adjList)
{
    int n=adjList.size();
    vector<int> visited(n,-1);
    
    for(int i=0;i<n;i++)
        if(visited[i]==-1)
            if(!BFS_Helper(adjList,i,visited))
                return false;
    return true;
}








int main()
{

}