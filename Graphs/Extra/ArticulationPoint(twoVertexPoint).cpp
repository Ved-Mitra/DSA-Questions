#include <bits/stdc++.h>
using namespace std;

//Articulation point
//Node on whose removal the graph breaks into multiple components

void DFS(vector<vector<int>> &adjList,int node,int &time,vector<bool> &mark,vector<bool> &visited,vector<int> &lowTime,vector<int> &discoveryTime,int parent)
{
    visited[node]=true;
    discoveryTime[node]=time++;
    lowTime[node]=discoveryTime[node];
    int child=0;
    for(int &x:adjList[node])
    {
        if(x==parent)
            continue;
        if(!visited[x])
        {
            child++;
            DFS(adjList,x,time,mark,visited,lowTime,discoveryTime,node);
            //take low time from all adjacent nodes except parent and visited node
            lowTime[node]=min(lowTime[node],lowTime[x]);
            //equal to as we need to have a connection to node with discovery time lower than node i.e. level above the node
            //as if we remove the starting node the graph stays as one whole component doesn't brings into components
            if(discoveryTime[node]<=lowTime[x] && parent!=-1)
                //used whether point or not as it may come to this conclusion many time and may add node more than 1 time
                    mark[node]=true;   
        }
        else    
            lowTime[node]=min(lowTime[node],discoveryTime[x]);
    }
    //if starting node has more than 1 child then it is articulation point 
    if(parent==-1 && child>1)
        mark[node]=true;
}

vector<int> PrintArticulationPoint(int n,vector<vector<int>> &edges)
{
    vector<vector<int>> adjList(n);
    for(int i=0;i<edges.size();i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    int time=0;
    vector<int> arrivalTime(n,-1);
    vector<int> lowTime(n,-1);
    vector<bool> visited(n,false);
    vector<int> points;
    vector<bool> mark(n,false);
    for(int i=0;i<n;i++)
        if(!visited[i])
            DFS(adjList,i,time,mark,visited,lowTime,arrivalTime,-1);
    for(int i=0;i<n;i++)
        if(mark[i])
            points.push_back(i);
    return points;
}

int main()
{

}