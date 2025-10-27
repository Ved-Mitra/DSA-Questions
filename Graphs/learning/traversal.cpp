#include <bits/stdc++.h>
using namespace std;

//assuming 1-indexed

vector<vector<int>> BFS()
{
    //TC-O(n)+O(degre=2*e)
    //SC-O(3n)
    //breadth first search
    //we will get the starting node
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> edges(m);
    for(int i=0;i<m;i++)
        cin >> edges[i].first >> edges[i].second;
    //define a visited array
    vector<bool> visited(n+1,false);
    //take staring node
    //use queue
    //use adjacency list
    vector<vector<int>> adjList(n+1);//sc-O(2n)
    for(int i=0;i<m;i++)
    {
        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }

    queue<int> q;
    vector<vector<int>> levelOrder;
    int x;//starting node
    cin >> x;
    q.push(x);
    visited[x]=true;
    while(!q.empty())
    {
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++)
        {
            int node=q.front();
            q.pop();
            int adjSize=adjList[node].size();
            level.push_back(node);
            for(int j=0;j<adjSize;j++)
                if(!visited[adjList[node][j]])
                {
                    q.push(adjList[node][j]);
                    visited[adjList[node][j]]=true;
                }
        }
        levelOrder.push_back(level);
    }
    return levelOrder;
}

vector<int> DFS()
{
    //depth first search
    //we will get the starting node
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> edges(m);
    for(int i=0;i<m;i++)
        cin >> edges[i].first >> edges[i].second;
    //define a visited array
    vector<bool> visited(n+1,false);
    //take staring node
    //use stack
    //use adjacency list
    vector<vector<int>> adjList(n+1);
    for(int i=0;i<m;i++)
    {
        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }

    int x;//starting node
    cin >> x;
    vector<int> ans;
    DFSHelper(adjList,x,ans,visited);
    return ans;
}
void DFSHelper(vector<vector<int>> &adjList,int node,vector<int> &ans,vector<bool> &visited)
{
    if(visited[node])
        return;
    int n=adjList[node].size();
    visited[node]=true;
    //ans.pus_back(node) //pre order
    for(int i=0;i<n;i++)
        DFSHelper(adjList,adjList[node][i],ans,visited);
    ans.push_back(node);//post order
}


int main()
{

}