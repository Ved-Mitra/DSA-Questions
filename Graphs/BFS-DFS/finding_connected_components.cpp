#include <bits/stdc++.h>
using namespace std;


void BFS(vector<vector<int>> &adjList,int i,vector<bool> &visited)
{
    queue<int> q;
    q.push(i);
    visited[i]=true;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int &x:adjList[node])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x]=true;
            }
        }
    }
}

int find_number_of_components(vector<vector<int>> &adjList,int n)
{
    int m=adjList.size();
    vector<bool> visited(n+1,false);
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(!visited[i])
        {
            BFS(adjList,i,visited);
            cnt++;
        }
    return cnt;
}



int main()
{

}