#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<char>> &board,vector<vector<bool>> &visited,int r,int c)
{
    int m=board.size();
    int n=board[0].size();
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

void solve(vector<vector<char>> &board)
{
    int m=board.size();
    int n=board[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(board[i][j]=='X')
                visited[i][j]=true;
    for(int i=0;i<n;i++)
        if(board[0][i]=='O' && !visited[0][i])
            BFS(board,visited,0,i);
    for(int i=0;i<n;i++)
        if(board[m-1][i]=='O' && !visited[m-1][i])
            BFS(board,visited,m-1,i);
    for(int i=0;i<m;i++)
        if(board[i][0]=='O' && !visited[i][0])
            BFS(board,visited,i,0);
    for(int i=0;i<m;i++)
        if(board[i][n-1]=='O' && !visited[i][n-1])
            BFS(board,visited,i,n-1);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(!visited[i][j])
                board[i][j]='X';
}


int main()
{
    
}