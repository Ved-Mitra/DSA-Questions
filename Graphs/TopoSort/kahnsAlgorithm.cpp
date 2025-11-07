#include <bits/stdc++.h>
using namespace std;


vector<int> TopoSort_BFS(vector<vector<int>> &adjList)
{
    //insert all nodes with incoming edge zero
    //take them out of queue
    int n=adjList.size();
    vector<int> inDegree(n,0);
    for(int i=0;i<n;i++)
        for(int j=0;j<adjList[i].size();j++)
            inDegree[adjList[i][j]]++;
    queue<int> q;
    for(int i=0;i<n;i++)
        if(inDegree[i]==0)
            q.push(i);
    vector<int> ans;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int &x:adjList[node])
        {
            inDegree[adjList[node][x]]--;
            if(inDegree[adjList[node][x]]==0)
                q.push(adjList[node][x]);
        }
    }
    return ans;
}


int main()
{
    
}