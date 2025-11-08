#include <bits/stdc++.h>
using namespace std;

//multiple source path algorithm
//detects negative cycle and negtive weight also
vector<int> FloydWarshall(vector<vector<int>> &edges,int n,int u)
{
    //go via every node
    //TC - O(n^3)
    //SC - O(n^2)
    vector<vector<int>> cost(n,vector(n,INT_MAX));
    for(int i=0;i<n;i++)
        cost[i][i]=0;
    for(int i=0;i<edges.size();i++)
        cost[edges[i][0]][edges[i][1]]=edges[i][2];
    
    for(int via=0;via<n;via++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cost[i][j]=min(cost[i][j],cost[i][via]+cost[via][j]);

    //to detect negative cycle
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(cost[i][j]<0)
                return {-1};

    return cost[u];    
}


int main()
{

}