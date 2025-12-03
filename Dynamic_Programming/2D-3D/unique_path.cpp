#include <bits/stdc++.h>
using namespace std;


int uniquePaths_Memoization(int m,int n,int row,int col,vector<vector<int>> &dp)
{
    //TC-O(2^(m+n))
    //SC-O((m-1)+(n-1)) + O(m*n)(dp)
    if(row>=m || col>=n)
        return 0;
    if(row==m-1 && col==n-1)
        return 1;
    if(dp[row][col]!=-1)
        return dp[row][col];
    return dp[row][col]=uniquePaths_Memoization(m,n,row+1,col,dp)+uniquePaths_Memoization(m,n,row,col+1,dp);
}

int uniquePaths_Tabulation(int m,int n)
{
    //TC-O(m*n)
    //SC-O(m*n)
    vector<vector<int>> dp(m,vector<int>(n,-1));
    dp[0][0]=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0)
                dp[0][0]=1;
            else
            {
                int up=0,left=0;
                if(i>0)
                    up=dp[i-1][j];
                if(j>0)
                    left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
    }
    return dp[m-1][n-1];
}

int uniquePaths_SC(int m,int n)
{
    //TC-O(m*n)
    //SC-O(m+n)
    vector<int> prevRow(n,-1);
    for(int i=0;i<m;i++)
    {
        vector<int> temp(n,0);
        for(int j=0;j<n;j++)
        {
            temp[j]=prevRow[j];
            if(j>0)
                temp[j]+=temp[j-1];
        }
        prevRow=temp;
    }
    return prevRow[n-1];
}


int main()
{

}