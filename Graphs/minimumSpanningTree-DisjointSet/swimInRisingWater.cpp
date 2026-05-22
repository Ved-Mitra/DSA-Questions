#include <bits/stdc++.h>
using namespace std;

int swimInWater(vector<vector<int>>& grid)
{
    int n=grid.size();
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    visited[0][0]=true;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({grid[0][0],0});
    while(!pq.empty())
    {
        int t=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        int y=node%n,x=(node-y)/n;
        if(x==n-1 && y==n-1)
            return t;
        if(x-1>=0 && !visited[x-1][y])
        {
            pq.push({max(grid[x-1][y],t),(x-1)*n + y});
            visited[x-1][y]=true;
        }
        if(x+1<n && !visited[x+1][y])
        {
            pq.push({max(grid[x+1][y],t),(x+1)*n +y});
            visited[x+1][y]=true;;
        }
        if(y+1<n && !visited[x][y+1])
        {
            pq.push({max(grid[x][y+1],t),x*n + y +1});
            visited[x][y+1]=true;
        }
        if(y-1>=0 && !visited[x][y-1])
        {
            pq.push({max(grid[x][y-1],t),x*n + y -1});
            visited[x][y-1]=true;
        }
    }
    return -1;
}









int main()
{

}