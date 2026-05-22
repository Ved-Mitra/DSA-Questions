#include <bits/stdc++.h>
using namespace std;

//QUERY TYPE QUESTION


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
        if(ultimateParent_u==ultimateParent_v)
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

vector<int> numIslands(int n,int m,vector<vector<int>> &query)
{
    vector<vector<int>> grid(m,vector<int>(n,0));
    DisjointSet st(m*n);
    vector<int> ans;
    for(int i=0;i<query.size();i++)
    {
        int x=query[i][0];
        int y=query[i][1];
        int node=x*n + y;
        grid[x][y]=1;
        if(x-1>=0 && grid[x-1][y]==1)
            st.unionBySize((x-1)*n + y,node);
        if(x+1<m && grid[x+1][y]==1)
            st.unionBySize((x+1)*n + y,node);
        if(y-1>=0 && grid[x][y-1]==1)
            st.unionBySize(x*n + y-1,node);
        if(y+1<n && grid[x][y+1]==1)
            st.unionBySize(x*n + y +1,node);
        int islands=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int Node=i*n + j;
                if(st.findParent(Node)==Node && grid[i][j]==1)
                    islands++;
            }
        }
        ans.push_back(islands);
    }
}




int main()
{

}