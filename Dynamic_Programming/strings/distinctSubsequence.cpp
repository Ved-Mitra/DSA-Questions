#include <bits/stdc++.h>
using namespace std;

int numDistinct_Memoization(string &s,string &t,int i,int j,vector<vector<double>> &dp)
{
    /*
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
        */
    if(j==0)
        return 1;

    if(i==0)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];
    
    if(s[i-1]==t[j-1])
    {
        dp[i][j]=numDistinct_Memoization(s,t,i-1,j-1,dp)+numDistinct_Memoization(s,t,i-1,j,dp);
    }
    else
        dp[i][j]=numDistinct_Memoization(s,t,i-1,j,dp);

    return (int)dp[i][j];
}

int numDistinct_Tabulation(string s,string t)
{
    int n=s.size();
    int m=t.size();
    vector<vector<double>> dp(n+1,vector<double>(m+1,0));

    //base condition
    for(int i=0;i<n;i++)
        dp[i][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][m];
}

int numDistinct_SC(string s,string t)
{
    int n=s.size();
    int m=t.size();
    vector<double> prev(m+1,0),curr(m+1,0);

    //base condition
    prev[0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                curr[j]=prev[j-1]+prev[j];
            }
            else
                curr[j]=prev[j];
        }
        prev=curr;
    }
    return prev[m];
}

int numDistinct_1D_OPTIMIZATION(string s,string t)
{
    int n=s.size();
    int m=t.size();
    vector<double> dp(m+1,0);

    //base condition
    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            if(s[i-1]==t[j-1])
            {
                dp[j]=dp[j-1]+dp[j];
            }
            // else
            //     dp[j]=dp[j];
        }
    }
    return dp[m];
}





int main()
{
    
}