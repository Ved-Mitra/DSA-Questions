#include <bits/stdc++.h>
using namespace std;


void BFS(vector<vector<int>> &adjList,int i,vector<int> &visited,int componentNumber)
{
    queue<int> q;
    q.push(i);
    visited[i]=componentNumber;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int &x:adjList[node])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x]=componentNumber;
            }
        }
    }
}

vector<int> find_number_of_components(vector<vector<int>> &adjList,int n)
{
    int m=adjList.size();
    vector<int> visited(n,-1);
    int cnt=1;
    for(int i=0;i<n;i++)
        if(visited[i]==-1)
        {
            BFS(adjList,i,visited,cnt);
            cnt++;
        }
    return visited;
}



int main()
{

}