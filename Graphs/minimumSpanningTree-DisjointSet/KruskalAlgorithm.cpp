#include <bits/stdc++.h>
using namespace std;

class DisjointSet//union by size
{
    private:
    vector<int> size,parent;
    public:
    DisjointSet(int n)
    {
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }

    int findParent(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int ultimateParent_u=findParent(u);
        int ultimateParent_v=findParent(v);
        if(ultimateParent_u=ultimateParent_v)
            return;
        if(ultimateParent_u=ultimateParent_v)
            return;
        if(size[ultimateParent_u]<size[ultimateParent_v])
        {
            parent[ultimateParent_u]=ultimateParent_v;
            size[ultimateParent_v]+=size[ultimateParent_u];
        }
        else
        {
            //if same then attach v-->u
            parent[ultimateParent_v]=ultimateParent_u;
            size[ultimateParent_u]+=size[ultimateParent_v];
        }
    }
};

vector<vector<int>> KruskalAlgorithm(vector<vector<pair<int,int>>> &adjList)
{
    //sort all the egdes by weight
    int n=adjList.size();
    vector<vector<int>> edges(n);
    for(int i=0;i<n;i++)//O(V+E)
        for(int j=0;j<adjList[i].size();j++)
        {
            //{weight,U,V}
            edges.push_back({adjList[i][j].second,i,adjList[i][j].first});
        }
    sort(edges.begin(),edges.end());// O(M log M)
    
    int sum=0;
    DisjointSet ds(n);
    vector<vector<int>>mst;
    for(int i=0;i<edges.size();i++)// O(M * 4 * alpha)
    {
        int u=edges[i][1];
        int v=edges[i][2];
        int wt=edges[i][0];
        if(ds.findParent(u)!=ds.findParent(v))
        {
            sum+=wt;
            ds.unionBySize(u,v);
            mst.push_back({u,v,wt});
        }
    }
    return mst;
}



int main()
{

}