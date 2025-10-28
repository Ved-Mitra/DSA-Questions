#include <bits/stdc++.h>
using namespace std;


//my solution
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int m = image.size();
    int n = image[0].size();
    int origin = image[sr][sc];
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    visited[sr][sc] = true;
    image[sr][sc] = color;
    while (!q.empty())
    {
        int l = q.size();
        for (int i = 0; i < l; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            cout << x << " " << y << endl;
            q.pop();
            if (x + 1 < m && image[x + 1][y] == origin && !visited[x + 1][y])
            {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
                image[x + 1][y] = color;
            }
            if (x - 1 >= 0 && image[x - 1][y] == origin && !visited[x - 1][y])
            {
                q.push({x - 1, y});
                visited[x - 1][y] = true;
                image[x - 1][y] = color;
            }
            if (y + 1 < n && image[x][y + 1] == origin && !visited[x][y + 1])
            {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
                image[x][y + 1] = color;
            }
            if (y - 1 >= 0 && image[x][y - 1] == origin && !visited[x][y - 1])
            {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
                image[x][y - 1] = color;
            }
        }
    }
    return image;
}

int main()
{

}