#include <bits/stdc++.h>
using namespace std;

int minPathSum_Memoization(vector<vector<int>> &grid,int m,int n,int r,int c,vector<vector<int>> &dp)
{
    //in calling main function
    //dp[0][0]=grid[0][0];
    if(r==0 && c==0)
        return grid[r][c];
    if(r<0 || c<0 || c>=n || r>=m)
        return 0;
    if(dp[r][c]!=-1)
        return dp[r][c];
    int up=grid[r][c],left=grid[r][c];
    if(r>0)
        up+=minPathSum_Memoization(grid,m,n,r-1,c,dp);
    if(c>0)
        left+=minPathSum_Memoization(grid,m,n,r,c-1,dp);
    if(r>0 && c>0)
        dp[r][c]=min(up,left);
    else if(r>0)
        dp[r][c]=up;
    else if(c>0)
        dp[r][c]=left;
    return dp[r][c];
}

int minPathSum_Tabulation(vector<vector<int>> &grid)
{
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0)
                dp[0][0]=grid[0][0];//base condition
            else
            {
                int up=grid[i][j],left=grid[i][j]; 
                if(i>0 && j>0)
                {
                    up+=dp[i-1][j];
                    left+=dp[i][j-1];
                    dp[i][j]=min(up,left);
                }
                else if(i>0)
                {
                    up+=dp[i-1][j];
                    dp[i][j]=up;
                }
                else if(j>0)
                {
                    left+=dp[i][j-1];
                    dp[i][j]=left;
                }
            }
        }
    }
    return dp[m-1][n-1];
}

int minPathSum_SC(vector<vector<int>> &grid)
{
    int m=grid.size();
    int n=grid[0].size();
    vector<int> dpRow(n,0);
    for(int i=0;i<m;i++)
    {
        vector<int> temp(n,0);
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0)
                temp[0]=grid[0][0];//base condition
            else
            {
                int up=grid[i][j],left=grid[i][j]; 
                if(i>0 && j>0)
                {
                    up+=dpRow[j];
                    left+=temp[j-1];
                    temp[j]=min(up,left);
                }
                else if(i>0)
                {
                    up+=dpRow[j];
                    temp[j]=up;
                }
                else if(j>0)
                {
                    left+=temp[j-1];
                    temp[j]=left;
                }
            }
        }
        dpRow=temp;
    }
    return dpRow[n-1];
}



int main()
{

}