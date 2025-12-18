#include <bits/stdc++.h>
using namespace std;

//s-->string
//p-->pattern

bool isMatch_Memoization(string &s,string &p,int i,int j,vector<vector<bool>> &dp)
{
    if(i<0 && j<0)
        return true;
    if(i<0)
    {
        for(int jj=0;jj<=j;jj++)
            if(p[jj]!='*')
                return false;
        return true;
    }
    if(i<0 || j<0)
        return false;

    if(dp[i][j]!=-1)
        return dp[i][j];
    
    if(s[i]==p[j] || p[j]=='?')
    {
        return dp[i][j]=isMatch_Memoization(s,p,i-1,j-1,dp);
    }
    else if(p[j]=='*')
    {
        return dp[i][j]=isMatch_Memoization(s,p,i,j-1,dp) || isMatch_Memoization(s,p,i-1,j,dp);
    }
    
    return dp[i][j]=false;
}

bool isMatch_Tabulation(string &s,string &p)
{
    int n=s.size();
    int m=p.size();

    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));

    //base condition
    dp[0][0]=true;
    for(int j=1;j<=m;j++)
    {
        if(p[j-1]=='*')
            dp[0][j]=true;
        else
            break;
    }

    //nested loops
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==p[j-1] || p[j-1]=='?')
                dp[i][j]=dp[i-1][j-1];
            else if(p[j-1]=='*')
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
        }
    }
    
    return dp[n][m];
}

bool isMatch_SC(string &s,string &p)
{
    int n=s.size();
    int m=p.size();

    vector<bool> prev(m+1,false),curr(m+1,false);

    //base condition
    prev[0]=true;
    for(int j=1;j<=m;j++)
    {
        if(p[j-1]=='*')
            prev[j]=true;
        else
            break;
    }

    //nested loops
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==p[j-1] || p[j-1]=='?')
                curr[j]=prev[j-1];
            else if(p[j-1]=='*')
                curr[j]=prev[j] || curr[j-1];
            else
                curr[j]=false;
        }
        prev=curr;
    }
    
    return prev[m];
}

bool isMatch_1D_OPTIMIZATION(string &s,string &p)
{
    int n=s.size();
    int m=p.size();

    vector<bool> dp(m+1,false);

    //base condition
    dp[0]=true;
    for(int j=1;j<=m;j++)
    {
        if(p[j-1]=='*')
            dp[j]=true;
        else
            break;
    }

    //nested loops
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            if(s[i-1]==p[j-1] || p[j-1]=='?')
                dp[j]=dp[j-1];
            else if(p[j-1]=='*')
                dp[j]=dp[j] || dp[j-1];
            else
                dp[j]=false;
        }
    }
    
    return dp[m];
}


int main()
{
    
}