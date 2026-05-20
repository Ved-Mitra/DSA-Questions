#include <bits/stdc++.h>
using namespace std;

// METHOD-1
void bfs(vector<vector<int>> &adjList, vector<int> &visited, int id, int node)
{
    queue<pair<int, int>> q;
    q.push({node, -1});
    visited[node] = id;
    int cycles = 0;
    while (!q.empty())
    {
        int u = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int i = 0; i < adjList[u].size(); i++)
        {
            int v = adjList[u][i];
            if (visited[v] == -1)
            {
                visited[v] = id;
                q.push({v, u});
            }
            else if (v != parent)
                cycles++;
        }
    }
    // return cycles-(cycles/2);
}
int makeConnected(int n, vector<vector<int>> &connections)
{
    if (connections.size() < n - 1)
        return -1;
    vector<vector<int>> adjList(n);
    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<int> visited(n, -1);
    int id = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == -1)
        {
            bfs(adjList, visited, id, i);
            // cout << i << " " << id << " " << cycles << '\n';
            id++;
        }
    }
    return id - 1;
}

// METHOD-2 (Optmized)
class DisjointSet
{
public:
    vector<int> rank, parent;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 1);
        // size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            // size[i] = 1;
        }
    }
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int makeConnected(int n, vector<vector<int>>& connections)
{
    int size = connections.size();

    if (size < n - 1)
        return -1;

    DisjointSet ds(n);

    for(int i=0;i<size;i++){
        ds.unionByRank(connections[i][0], connections[i][1]);
    }
    int cnt=0;
        for(int i=0; i<n; i++) {
        if(ds.parent[i] == i) cnt++;
    }

    return cnt-1;
}


int main()
{
}