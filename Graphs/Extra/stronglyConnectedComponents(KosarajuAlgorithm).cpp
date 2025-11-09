#include <bits/stdc++.h>
using namespace std;

//SCC only valid for directed graph
//in interview either print SCC or number of SCC
//SCC : very pair of vertex is rechable in both ways

void DFS1(vector<vector<int>> &adjList,stack<int> &st,vector<bool> &visited,int node)
{
    visited[node]=true;
    for(int &x:adjList[node])
        if(!visited[x])
            DFS1(adjList,st,visited,x);
    st.push(node);
}
void DFS2(vector<vector<int>> &revAdjList,int node,vector<int> &nodesVisitedOnIteration,vector<bool> &visited)
{
    visited[node]=true;
    nodesVisitedOnIteration.push_back(node);
    for(int &x:revAdjList[node])
        if(!visited[x])
            DFS2(revAdjList,x,nodesVisitedOnIteration,visited);
}
vector<vector<int>> stronglyConnectedComponents(vector<vector<int>> &adjList)
{
    int n=adjList.size();
    vector<vector<int>> revAdjList(n);
    vector<vector<int>> scc;
    //1. sort all edges according to the finishing time
    //2. reverse the graph
    //3. do a dfs

    //1.
    //TC - O(V+E)
    vector<bool> visited(n,false);
    stack<int> st;
    for(int i=0;i<n;i++)
        if(!visited[i])
            DFS1(adjList,st,visited,i);
    
    //2.
    //TC - O(V+E)
    for(int i=0;i<n;i++)
        for(int j=0;j<adjList[i].size();j++)
            revAdjList[adjList[i][j]].push_back(i);

    //3.
    //TC - O(V+E)
    for(int i=0;i<n;i++)
        visited[i]=false;
    while(!st.empty())
    {
        int i=st.top();
        st.pop();
        if(!visited[i])
        {
            vector<int> nodesVisitedOnIteration;
            DFS2(revAdjList,i,nodesVisitedOnIteration,visited);
            scc.push_back(nodesVisitedOnIteration);
        }
    }
    return scc;
}

int main()
{

}