#include <bits/stdc++.h>
using namespace std;

//brute generate all subsequences and compare them

string printLongestSubsequence(string &text1,string &text2,vector<vector<int>> &dp)
{
    int n=text1.size();
    int m=text2.size();

    vector<char> ans(dp[n][m]);
    int index=dp[n][m]-1;
    int i=n,j=m;
    while(index>=0 && i>0 && j>0)//no need for region where either i==0 || j==0 as treated as index: -1
    {
        if(text1[i-1]==text2[j-1])
        {
            ans[index]=text1[i-1];
            i--;
            j--;
            index--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    string str="";
    for(int k=0;k<ans.size();k++)
        str+=ans[k];
    return str;
}

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

    //after memoization just do the following steps as in tabulation
}

string longestCommonSubsequence_Tabulation(string text1, string text2)
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
    return printLongestSubsequence(text1,text2,dp);
}

string longestCommonSubsequence_SC(string text1, string text2)
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
    

}


int main()
{

}