#include <bits/stdc++.h>
using namespace std;

int recursive_helper(vector<vector<int>> &mat,int r,int c,int n,vector<vector<int>> &dp)
{
    if(c>=n || c<0)
        return 1e9;

    if(r==n-1)
        return mat[n-1][c];

    if(dp[r][c]!=-1)
        return dp[r][c];
    
    int down =recursive_helper(mat,r+1,c,n,dp);
    int diagonalRight=recursive_helper(mat,r+1,c+1,n,dp);
    int diagonalLeft=recursive_helper(mat,r+1,c-1,n,dp);

    return dp[r][c]=mat[r][c]+min(down,min(diagonalLeft,diagonalRight));
}
int minimumFallingPathSum_Memoization(vector<vector<int>> &mat)
{
    int n=mat.size();
    int ans=INT_MAX;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++)
    {
        ans=min(ans,recursive_helper(mat,0,i,n,dp));
    }
    return ans;
}

int minimumFallingPathSum_Tabulation(vector<vector<int>> &mat)
{
    int n=mat.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++)
        dp[n-1][i]=mat[n-1][i];
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            int down,diagonalLeft=1e9,diagonalRight=1e9;
            down = dp[i+1][j];
            if(j>0) diagonalLeft=dp[i+1][j-1];
            if(j<n-1)   diagonalRight=dp[i+1][j+1];
            dp[i][j]=mat[i][j]+ min(down,min(diagonalLeft,diagonalRight));
        }
        
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
        ans=min(ans,dp[0][i]);
    return ans;
}

int minimumFallingPathSum_SC(vector<vector<int>> &mat)
{
    int n=mat.size();
    vector<int> dp(n,-1),temp(n);
    for(int i=0;i<n;i++)
        dp[i]=mat[n-1][i];
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            int down,diagonalLeft=1e9,diagonalRight=1e9;
            down = dp[j];
            if(j>0)     diagonalLeft=dp[j-1];
            if(j<n-1)   diagonalRight=dp[j+1];
            temp[j]=mat[i][j]+ min(down,min(diagonalLeft,diagonalRight));
        }
        dp=temp;
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
        ans=min(ans,dp[i]);
    return ans;
}


int main()
{

}