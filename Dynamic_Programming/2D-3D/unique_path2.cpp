#include <bits/stdc++.h>
using namespace std;

//with obstacle

int uniquePath_Memoization(vector<vector<int>> &obstacleGrid,int m,int n,int r,int c,vector<vector<int>> &dp)
{
    //start from m-1,n-1
    if(r==0 && c==0 && obstacleGrid[0][0]!=1)
        return dp[r][c]=1;
    if(r<0 || c<0 || r>=m || c>=n)
        return 0;
    if(obstacleGrid[r][c]==1)
        return 0;
    if(dp[r][c]!=-1)
        return dp[r][c];
    return dp[r][c]=uniquePath_Memoization(obstacleGrid,m,n,r-1,c,dp)+uniquePath_Memoization(obstacleGrid,m,n,r,c-1,dp);
}

int uniquePath_Tabulation(vector<vector<int>> &obstacleGrid)
{
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    if(obstacleGrid[0][0]==1)
        return 0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(obstacleGrid[i][j]==1)
                continue;
            if(i==0 && j==0)
                dp[0][0]=1;
            else
            {
                int up=0,down=0;
                if(i>0)
                    up=dp[i-1][j];
                if(j>0)
                    down=dp[i][j-1];
                dp[i][j]=up+down;
            }
        }
    }
    return dp[m-1][n-1];
}

int uniquePath_SC(vector<vector<int>> &obstacleGrid)
{
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    if(obstacleGrid[0][0]==1)
        return 0;
    vector<int> dpRow(n,0);
    for(int i=0;i<m;i++)
    {
        vector<int> temp(n,0);
        for(int j=0;j<n;j++)
        {
            if(obstacleGrid[i][j]==1)
                continue;
            if(i==0 && j==0)
            {
                dpRow[0]=1;
                temp[0]=1;
            }
            else
            {
                temp[j]=dpRow[j];
                if(j>0)
                    temp[j]+=temp[j-1];
            }
        }
        dpRow=temp;
    }
    return dpRow[n-1];
}

int main()
{
    
}