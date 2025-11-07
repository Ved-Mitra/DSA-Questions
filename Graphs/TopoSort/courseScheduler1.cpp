#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<vector<int>> adjList(numCourses);
    for(int i=0;i<prerequisites.size();i++)
    {
        adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
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
            return false;
    return true;
}


int main()
{

}