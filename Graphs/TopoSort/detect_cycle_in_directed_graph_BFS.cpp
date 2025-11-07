#include <bits/stdc++.h>
using namespace std;


bool detectCycleInDirectedGraph_BFS(vector<vector<int>> &adjList)
{
    int n=adjList.size();
    vector<int> inDegree(n,0);
    for(int i=0;i<n;i++)
        for(int j=0;j<adjList[i].size();j++)
            inDegree[adjList[i][j]]++;
    queue<int> q;
    for(int i=0;i<n;i++)
        if(inDegree[i]==0)
            q.push(i);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int &x:adjList[node])
        {
            inDegree[x]--;
            if(inDegree[x]==0)
                q.push(x);
        }
    }
    for(int i=0;i<n;i++)
        if(inDegree[i]!=0)
            return true;
    return false;
}

int main()
{

}