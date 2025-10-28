#include <bits/stdc++.h>
using namespace std;

//my solution
//TC-O(m*n)
//SC-O(m*n)
int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int cnt = 0;
    int time = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                cnt++;
            else if (grid[i][j] == 2)
                q.push({i, j});
        }
    while (!q.empty())
    {
        int l = q.size();
        int flag = 0;
        for (int i = 0; i < l; i++)
        {
            pair<int, int> pos = q.front();
            q.pop();
            int x = pos.first;
            int y = pos.second;
            if (x + 1 < m && y < n && grid[x + 1][y] == 1)
            {
                flag = 1;
                cnt--;
                grid[x + 1][y] = 2;
                q.push({x + 1, y});
            }
            if (x - 1 >= 0 && y < n && grid[x - 1][y] == 1)
            {
                flag = 1;
                cnt--;
                grid[x - 1][y] = 2;
                q.push({x - 1, y});
            }
            if (x < m && y + 1 < n && grid[x][y + 1] == 1)
            {
                flag = 1;
                cnt--;
                grid[x][y + 1] = 2;
                q.push({x, y + 1});
            }
            if (x < m && y - 1 >= 0 && grid[x][y - 1] == 1)
            {
                flag = 1;
                cnt--;
                grid[x][y - 1] = 2;
                q.push({x, y - 1});
            }
        }
        if (flag)
            time++;
    }

    if (cnt == 0)
        return time;
    return -1;
}



int main()
{

}