#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMaze(vector<vector<int>> &grid)
{
    //using queue as unit weight
    int n=grid.size();
    vector<vector<int>>dist(n,vector(n,INT_MAX));
    dist[0][0]=1;
    if(grid[0][0]==1 || grid[n-1][n-1]==1)
        return -1;
    int row[]={-1,-1,0,+1,+1,+1,0,-1};
    int col[]={0,+1,+1,+1,0,-1,-1,-1};
    queue<pair<int,pair<int,int>>>pq;
    pq.push({1,{0,0}});
    while(!pq.empty())
    {
        int dNode=pq.front().first;
        int r=pq.front().second.first;
        int c=pq.front().second.second;
        pq.pop();
        for(int i=0;i<8;i++)
        {
            int x=r+row[i];
            int y=c+col[i];
            if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==0 && dist[x][y]>1+dNode)
            {
                dist[x][y]=1+dNode;
                pq.push({dist[x][y],{x,y}});
            }
            if(x==n-1 && y==n-1)
                return dNode+1;
        }
    }
    if(dist[n-1][n-1]==INT_MAX)
        return -1;
    return dist[n-1][n-1];
}

int main()
{

}