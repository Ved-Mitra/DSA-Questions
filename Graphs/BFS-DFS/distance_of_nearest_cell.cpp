#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        ans[x][y] = d;
        if (x + 1 < m && !visited[x + 1][y])
        {
            q.push({{x + 1, y}, d + 1});
            visited[x + 1][y] = true;
        }
        if (y + 1 < n && !visited[x][y + 1])
        {
            q.push({{x, y + 1}, d + 1});
            visited[x][y + 1] = true;
        }
        if (x - 1 >= 0 && !visited[x - 1][y])
        {
            q.push({{x - 1, y}, d + 1});
            visited[x - 1][y] = true;
        }
        if (y - 1 >= 0 && !visited[x][y - 1])
        {
            q.push({{x, y - 1}, d + 1});
            visited[x][y - 1] = true;
        }
    }
    return ans;
}

int main()
{
}