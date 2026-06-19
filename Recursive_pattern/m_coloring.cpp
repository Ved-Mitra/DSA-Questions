#include<bits/stdc++.h>
using namespace std;

/*
given an undirected graph and integer M
the task is to determine if the graph can be colored with at most M color suct that no adjacent vertices of graph are colored with the same color.
*/
//return 1 or 0
bool helper(vector<vector<int>> &adjList,int node,vector<int> &colors,int m)
{
    if(node==adjList.size())
        return true;
    
    for(int color=1;color<=m;color++)
    {
        bool flag=true;
        for(auto x:adjList[node])
        {
            if(colors[x]==color)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            colors[node]=color;
            if(helper(adjList,node+1,colors,m))
                return true;
            colors[node]=-1;
        }
    }
    return false;
}
bool graphColoring(int v, vector<vector<int>> &edges, int m) {
    // code here
    int n=v;
    vector<vector<int>> adjList(n);
    for(int i=0;i<edges.size();i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> colors(n,-1);
    return helper(adjList,0,colors,m);
}

int main()
{

}
