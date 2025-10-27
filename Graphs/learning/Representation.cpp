#include <bits/stdc++.h>
using namespace std;

//ways of representation is adjacency matrix, adjacency list

//undirected Graph
void adjacencyMatrix(int n,int m,vector<pair<int,int>> edge)
{
    vector<vector<int>> adjMat(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++)
    {
        adjMat[edge[i].first][edge[i].second]=1;
        adjMat[edge[i].second][edge[i].first]=1;
    }
}
void adjacencyList(int n,int m,vector<pair<int,int>> edge)
{
    vector<vector<int>> adjList(n+1);
    for(int i=0;i<m;i++)
    {
        adjList[edge[i].first].push_back(edge[i].second);
        adjList[edge[i].second].push_back(edge[i].first);
    }
}

//directedGraph
void adjacencyMatrix(int n,int m,vector<pair<int,int>> edge)
{
    vector<vector<int>> adjMat(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++)
    {
        adjMat[edge[i].first][edge[i].second]=1;
    }
}
void adjacencyList(int n,int m,vector<pair<int,int>> edge)
{
    vector<vector<int>> adjList(n+1);
    for(int i=0;i<m;i++)
    {
        adjList[edge[i].first].push_back(edge[i].second);
    }
}


//weighted Graph
void adjacencyMatrix(int n,int m,vector<pair<int,int>> edge,vector<int>weight)
{
    vector<vector<int>> adjMat(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++)
    {
        adjMat[edge[i].first][edge[i].second]=weight[i];
        adjMat[edge[i].second][edge[i].first]=weight[i];
    }
}
void adjacencyList(int n,int m,vector<pair<int,int>> edge,vector<int>weight)
{
    vector<vector<pair<int,int>>> adjList(n+1);
    for(int i=0;i<m;i++)
    {
        adjList[edge[i].first].push_back({edge[i].second,weight[i]});
        adjList[edge[i].second].push_back({edge[i].first,weight[i]});
    }
}

int main()
{
    // first take input n(number of nodes) & m(number of edges)
    int m,n;
    cin >> n >> m;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++)
        cin >> edges[i].first >> edges[i].second;
}