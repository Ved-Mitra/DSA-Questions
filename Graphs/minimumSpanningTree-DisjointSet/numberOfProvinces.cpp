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

int numberOfProvinces(vector<vector<int>> &adjMat)
{
    int n=adjMat.size();
    DisjointSet ds(n);
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(adjMat[i][j]==1)
                ds.unionBySize(i,j);
    
    //now just calculate the number of ultimate bosses
    for(int i=0;i<n;i++)
        if(ds.findParent(i)==i)
            cnt++;
    return cnt;
}

int main()
{

}