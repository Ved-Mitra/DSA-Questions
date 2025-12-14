#include <bits/stdc++.h>
using namespace std;

/*given rod length and prices for length from 0-->n-1 is given you cut the rod such that you get the highest price*/

int maxPrice_Memoization(vector<int> &prices,int length,int i,vector<vector<int>> &dp)
{
    if(i==0)
        return length*prices[0];

    if(dp[i][length]!=-1)
        return dp[i][length];

    int notCut=0+maxPrice_Memoization(prices,length,i-1,dp);
    int cut=0;
    if(length>=i+1)
        cut=prices[i]+maxPrice_Memoization(prices,length-i-1,i,dp);
    return dp[i][length]=max(cut,notCut);
}

int maxPrice_Tabulation(vector<int> &prices,int rodLength)
{
    int n=prices.size();
    vector<vector<int>> dp(n,vector<int>(rodLength+1,0));

    //base condition
    for(int i=0;i<=rodLength;i++)
        dp[0][i]=i*prices[0];
    
    //nested loops
    for(int i=1;i<n;i++)
    {
        for(int length=0;length<=rodLength;length++)
        {
            int notCut=dp[i-1][length];
            int cut=0;
            if(length>=i+1)
                cut=prices[i]+dp[i][length-i-1];
            dp[i][length]=max(cut,notCut);
        }
    }
    return dp[n-1][rodLength];
}

int maxPrice_SC(vector<int> &prices,int rodLength)
{
    int n=prices.size();
    vector<int> prev(rodLength+1,0),curr(rodLength+1,0);

    //base condition
    for(int i=0;i<=rodLength;i++)
        prev[i]=i*prices[0];
    
    //nested loops
    for(int i=1;i<n;i++)
    {
        for(int length=0;length<=rodLength;length++)
        {
            int notCut=prev[length];
            int cut=0;
            if(length>=i+1)
                cut=prices[i]+curr[length-i-1];
            curr[length]=max(cut,notCut);
        }
        prev=curr;
    }
    return prev[rodLength];
}

int maxPrices_1D_OPTIMIZATION(vector<int> &prices,int rodLength)
{
    int n=prices.size();
    vector<int> dp(rodLength+1,0);

    //base condition
    for(int i=0;i<=rodLength;i++)
        dp[i]=i*prices[0];
    
    //nested loops
    for(int i=1;i<n;i++)
    {
        for(int length=0;length<=rodLength;length++)
        {
            int notCut=dp[length];
            int cut=0;
            if(length>=i+1)
                cut=prices[i]+dp[length-i-1];
           dp[length]=max(cut,notCut);
        }
    }
    return dp[rodLength];
}

int main()
{

}