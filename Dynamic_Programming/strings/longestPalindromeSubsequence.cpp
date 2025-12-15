#include <bits/stdc++.h>
using namespace std;

int longestPalindromeSubsequence(string s)
{
    int n=s.size();

    string text1=s,text2=s;
    reverse(text2.begin(),text2.end());

    //use text1 and text2 from here to call longestCommonSubsequence problem
}

#include <bits/stdc++.h>
using namespace std;

//brute generate all subsequences and compare them

int longestCommonSubsequence_Memoization(string text1, string text2,int i,int j,vector<vector<int>> &dp)
{
    //dp-->(n+1)(m+1)
    //shifting index for base condtion
    //index:n-1 -- > n
    //index:0   -- > 1
    //index:-1  -- > 0
    //TC-O(m*n)
    //SC-O(m*n) + O(m+n)
    if(i==0 || j==0) //i<0 || j<0
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];
    
    if(text1[i-1]==text2[j-1])
        dp[i][j]=1+longestCommonSubsequence_Memoization(text1,text2,i-1,j-1,dp);
    else
    {
        int p1=longestCommonSubsequence_Memoization(text1,text2,i-1,j,dp);
        int p2=longestCommonSubsequence_Memoization(text1,text2,i,j-1,dp);

        dp[i][j]=max(p1,p2);
    }    
    return dp[i][j];
}

int longestCommonSubsequence_Tabulation(string text1, string text2)
{
    int n=text1.size();
    int m=text2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));//just shifting index for base condtion
    //index:n-1 -- > n
    //index:0   -- > 1
    //index:-1  -- > 0

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int longestCommonSubsequence_SC(string text1, string text2)
{
    int n=text1.size();
    int m=text2.size();

    vector<int> prev(m+1,0),curr(m+1,0);//just shifting index for base condtion
    //index:n-1 -- > n
    //index:0   -- > 1
    //index:-1  -- > 0

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                curr[j]= 1 + prev[j-1];
            }
            else
            {
                curr[j]=max(prev[j],curr[j-1]);
            }
        }
        prev=curr;
    }
    return prev[m];
}


int main()
{

}


int main()
{

}