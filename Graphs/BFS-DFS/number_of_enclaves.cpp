#include <bits/stdc++.h>
using namespace std;


void BFS(vector<vector<int>> &grid,vector<vector<bool>> &visited,int r,int c)
{
    int m=grid.size();
    int n=grid[0].size();
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c]=true;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x+1<m && !visited[x+1][y])
        {
            visited[x+1][y]=true;
            q.push({x+1,y});
        }
        if(y+1<n && !visited[x][y+1])
        {
            visited[x][y+1]=true;
            q.push({x,y+1});
        }
        if(x-1>=0 && !visited[x-1][y])
        {
            visited[x-1][y]=true;
            q.push({x-1,y});
        }
        if(y-1>=0 && !visited[x][y-1])
        {
            visited[x][y-1]=true;
            q.push({x,y-1});
        }
    }
}

int numEnclaves(vector<vector<int>>& grid)
{
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j]==0)
                visited[i][j]=true;
    for(int i=0;i<n;i++)
        if(grid[0][i]==1 && !visited[0][i])
            BFS(grid,visited,0,i);
    for(int i=0;i<n;i++)
        if(grid[m-1][i]==1 && !visited[m-1][i])
            BFS(grid,visited,m-1,i);
    for(int i=0;i<m;i++)
        if(grid[i][0]==1 && !visited[i][0])
            BFS(grid,visited,i,0);
    for(int i=0;i<m;i++)
        if(grid[i][n-1]==1 && !visited[i][n-1])
            BFS(grid,visited,i,n-1);
    int cnt=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(!visited[i][j])
                cnt++;
    return cnt;
}
int main()
{

}