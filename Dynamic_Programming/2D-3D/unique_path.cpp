#include <bits/stdc++.h>
using namespace std;


int uniquePaths_Memoozation(int m,int n,int row,int col,vector<vector<int>> &dp)
{
    if(row>=m || col>=n)
        return 0;
    if(row==m-1 && col==n-1)
        return 1;
    if(dp[row][col]!=-1)
        return dp[row][col];
    return dp[row][col]=uniquePaths_Memoozation(m,n,row+1,col,dp)+uniquePaths_Memoozation(m,n,row,col+1,dp);
}

int uniquePaths_Tabulation(int m,int n)
{
    vector<vector<int>> dp(m,vector<int>(n,-1));
    
}


int main()
{

}