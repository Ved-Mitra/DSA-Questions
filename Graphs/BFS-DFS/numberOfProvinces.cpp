#include <bits/stdc++.h>
using namespace std;


//my solution
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<int> visited(n, false);
    int cnt = 1;
    queue<int> q;
    q.push(0);
    while (true)
    {
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();
                visited[node] = true;
                for (int j = 0; j < n; j++)
                {
                    if (isConnected[node][j] && !visited[j])
                        q.push(j);
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < n; i++)
            if (!visited[i])
            {
                flag = 1;
                q.push(i);
                break;
            }
        if (flag)
        {
            cnt++;
        }
        else
            break;
    }
    return cnt;
}

//Striver solution
int numProvinces(vector<vector<int>> &isConnected)
{
    //TC-O(2*e + v) + O(n)
        //partial DFS + for loop
    //SC-O(2n)
    vector<vector<int>> adjList;
    int n=isConnected.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(isConnected[i][j]==1 && i!=j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
    }
    vector<bool> visited(n,false);
    int cnt=0;
    for(int i=0;i<n;i++)
        if(!visited[i])
        {
            cnt++;
            DFS(adjList,i,visited);
        }
    return cnt;
}
void DFS(vector<vector<int>> &adjList,int node,vector<bool> &visited)
{
    if(visited[node])
        return;
    int n=adjList[node].size();
    visited[node]=true;
    for(int i=0;i<n;i++)
        DFS(adjList,adjList[node][i],visited);
}
int main()
{

}