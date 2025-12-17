#include <bits/stdc++.h>
using namespace std;

int minDistance_Memoization(string &word1, string &word2,int i,int j,vector<vector<int>> &dp)
{
    if(j<0)
        return i+1;
    
    if(i<0)
        return j+1;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(word1[i]==word2[j])
        return dp[i][j]=minDistance_Memoization(word1,word2,i-1,j-1,dp);
    
    return dp[i][j]=1+min(minDistance_Memoization(word1,word2,i,j-1,dp),min(minDistance_Memoization(word1,word2,i-1,j,dp),minDistance_Memoization(word1,word2,i-1,j-1,dp)));
    //min ( insert , min (delete, replace))
}

int minDistance_Tabulation(string word1, string word2)
{
    int n=word1.size();
    int m=word2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //base conditions
    for(int i=0;i<=n;i++)
        dp[i][0]=i;
    for(int j=0;j<=m;j++)
        dp[0][j]=j;
    
    /// nested loops
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(word1[i-1]==word2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    return dp[n][m];
}

int minDistance_SC(string word1, string word2)
{
    int n=word1.size();
    int m=word2.size();

    vector<int> prev(m+1,0),curr(m+1,0);

    //base conditions
    for(int j=0;j<=m;j++)
        prev[j]=j;
    
    /// nested loops
    for(int i=1;i<=n;i++)
    {
        curr[0]=i;
        for(int j=1;j<=m;j++)
        {
            if(word1[i-1]==word2[j-1])
                curr[j]=prev[j-1];
            else
                curr[j]=1+min(curr[j-1],min(prev[j],prev[j-1]));
        }
        prev=curr;
    }
    return prev[m];
}



int main()
{

}