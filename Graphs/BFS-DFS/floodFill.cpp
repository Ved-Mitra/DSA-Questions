#include <bits/stdc++.h>
using namespace std;

// my solution
// done by BFS
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

// striver solution
// done by DFS
//  The 'iniColor' parameter is added to the function signature based on its usage
//  within the function and how it's called from the floodFill method.
void dfs(int row, int col, vector<vector<int>> &ans,vector<vector<int>> &image, int newColor, int delRow[],int delCol[], int iniColor)
{
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        // The condition 'ans[nrow][ncol] != newColor' is a logical completion
        // of the partially visible line in the image.
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
        {
            dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image,int sr, int sc, int newColor)
{
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    // Note: A common edge case to handle is `if (iniColor == newColor) return image;`
    // to prevent unnecessary computation or infinite loops, though it's not in the original image.

    dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
    return ans;
}

int main()
{

}