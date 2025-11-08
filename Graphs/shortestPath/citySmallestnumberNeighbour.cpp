#include <bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
{
    vector<vector<int>> cost(n,vector(n,INT_MAX));
    for(int i=0;i<n;i++)
        cost[i][i]=0;
    for(int i=0;i<edges.size();i++)
    {
        cost[edges[i][0]][edges[i][1]]=edges[i][2];
        cost[edges[i][1]][edges[i][0]]=edges[i][2];
    }
    
    for(int via=0;via<n;via++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(cost[i][via]!=INT_MAX && cost[via][j]!=INT_MAX)
                cost[i][j]=min(cost[i][j],cost[i][via]+cost[via][j]);
    
    int city=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
            if(cost[i][j]<=distanceThreshold && cost[i][j]!=0)
                cnt++;
        if(i==0)
            count=cnt;
        if(cnt<=count)
        {
            city=i;
            count=cnt;
        }
    }
    return city;
}


int main()
{

}