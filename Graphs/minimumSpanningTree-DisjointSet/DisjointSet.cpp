#include <bits/stdc++.h>
using namespace std;

//V.V.V important
//used in Dynamic graph
//does what BFS or DFS does in O(1)

//gives findParent() , Union()(by rank or size)

//1. find ultimate parent of u and v
//2. find rank of ultimate parent
//3. connect smaller rank to larger rank

//TC - O(4 * alpha) alpha ~ 1
//See mathematic derivation of alpha from internet

class DisjointSet//union by rank
{
    private:
    vector<int> rank,parent;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
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

    void unionByRank(int u,int v)
    {
        int ultimateParent_u=findParent(u);
        int ultimateParent_v=findParent(v);
        if(ultimateParent_u==ultimateParent_v)
            return;
        if(rank[ultimateParent_u]>rank[ultimateParent_v])
            parent[ultimateParent_v]=ultimateParent_u;
        else if(rank[ultimateParent_u]<rank[ultimateParent_v])
            parent[ultimateParent_u]=ultimateParent_v;
        else
        {
            //if same then attach v-->u
            parent[ultimateParent_v]=ultimateParent_u;
            rank[ultimateParent_u]++;
        }
    }
};


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

//use either union by rank or size


int main()
{

}