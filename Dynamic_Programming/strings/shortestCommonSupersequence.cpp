#include <bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string &text1,string &text2)
{
    int n=text1.size();
    int m=text2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(text1[i-1]==text2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    int i=n,j=m;
    string str="";
    while(i>0 && j>0)
    {
        if(text1[i-1]==text2[j-1])
        {
            str+=text1[i-1];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(str.begin(),str.end());
    return str;
}

string shortestCommonSupersequence(string str1,string str2)
{
    string commonSubsequence=longestCommonSubsequence(str1,str2);

    string ans="";
    int i=0,j=0,index=0;
    int n=str1.size();
    int m=str2.size();
    while(i<n && j<m)
    {
        if(commonSubsequence[index]==str1[i] && commonSubsequence[index]==str2[j])
        {
            ans+=commonSubsequence[index];
            index++;
            i++;
            j++;
        }
        else if(commonSubsequence[index]==str1[i])
        {
            ans+=str2[j];
            j++;
        }
        else
        {
            ans+=str1[i];
            i++;
        }
    }
    while(i<n)
    {
        ans+=str1[i];
        i++;
    }
    while(j<m)
    {
        ans+=str2[j];
        j++;
    }
    return ans;
}








int main()
{

}