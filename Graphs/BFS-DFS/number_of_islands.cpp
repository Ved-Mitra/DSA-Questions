#include <bits/stdc++.h>
using namespace std;

/*Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid)
consisting of '0's (Water) and'1's(Land). Find the number of islands.

Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally
or vertically or diagonally i.e., in all 8 directions*/



void BFS(vector<vector<char>> &location,vector<vector<bool>> &visited,int r,int c)
{
    int n=location.size();
    int m=location[0].size();
    queue<pair<int,int>> q;
    q.push({r,c});
    while(!q.empty())
    {
        int l=q.size();
        for(int i=0;i<l;i++)
        {
            pair<int,int> pos=q.front();
            q.pop();
            int x=pos.first;
            int y=pos.second;
            //cout << x << " " << y << endl;
            if (x + 1 < n && !visited[x + 1][y] && location[x+1][y]=='1')
            {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
            }
            if (x - 1 >= 0 && !visited[x - 1][y] && location[x-1][y]=='1')
            {
                q.push({x - 1, y});
                visited[x - 1][y] = true;
            }
            if (y + 1 < m && !visited[x][y + 1] && location[x][y+1]=='1')
            {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
            }
            if (y - 1 >= 0 && !visited[x][y - 1] && location[x][y-1]=='1')
            {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
            }
            if(x+1<n && y+1<m && !visited[x+1][y+1] && location[x+1][y+1]=='1')
            {
                q.push({x+1,y+1});
                visited[x+1][y+1]=true;
            }
            if(x+1<n && y-1>=0 && !visited[x+1][y-1] && location[x+1][y-1]=='1')
            {
                q.push({x+1,y-1});
                visited[x+1][y-1]=true;
            }if(x-1>=0 && y+1<m && !visited[x-1][y+1] && location[x-1][y+1]=='1')
            {
                q.push({x-1,y+1});
                visited[x-1][y+1]=true;
            }if(x-1>=0 && y-1>=0 && !visited[x-1][y-1] && location[x-1][y-1]=='1')
            {
                q.push({x-1,y-1});
                visited[x-1][y-1]=true;
            }
        }
    }
}
int numberOfIslands(vector<vector<char>> &location)
{
    int n=location.size();
    int m=location[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(location[i][j]==1 && !visited[i][j])
            {
                cnt++;
                BFS(location,visited,i,j);
            }
    return cnt;
}


int main()
{

}