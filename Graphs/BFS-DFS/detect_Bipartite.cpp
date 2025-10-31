#include <bits/stdc++.h>
using namespace std;

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



int main()
{

}