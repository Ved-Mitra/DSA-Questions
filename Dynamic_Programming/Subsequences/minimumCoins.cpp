#include <bits/stdc++.h>
using namespace std;

int coinChange_Memoization(vector<int>& coins, int amount,int i,vector<vector<int>> &dp)
{
    //vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    if(amount==0)
        return 0;
    if(i==0)
    {
        if(amount%coins[0]==0)
            return amount/coins[0];
        return 1e9;
    }

    if(dp[i][amount]!=-1)
        return dp[i][amount];
    
    int notTake=0 + coinChange_Memoization(coins,amount,i-1,dp);
    int take=INT_MIN;
    if(coins[i]<=amount)
        take=1+coinChange_Memoization(coins,amount,i,dp);
    return dp[i][amount]=min(notTake,take);
}

int coinChange_Tabulation(vector<int>& coins, int amount)
{
    if(amount==0)
        return 0;
    int n=coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,0));

    //base conditions
    for(int i=0;i<=amount;i++)
    {
        if(i%coins[0]==0)
            dp[0][i]=i/coins[0];
        else
            dp[0][i]=1e9;
    }
    for(int i=0;i<n;i++)
        dp[i][0]=0;
        
    //nested loops
    for(int i=1;i<n;i++)
    {
        for(int money=0;money<=amount;money++)
        {
            int notTake= 0 + dp[i-1][money];
            int take=INT_MAX;
            if(money>=coins[i])
                take=1+dp[i][money-coins[i]];
            dp[i][money]=min(notTake,take);
        }
    }
    int result=dp[n-1][amount];
    if(result>=1e9)
        return -1;
    return result;
}

int coinChange_SC(vector<int>& coins, int amount)
{
    if(amount==0)
        return 0;
    int n=coins.size();
    vector<int> prev(amount+1,0),curr(amount+1,0);

    //base conditions
    for(int i=0;i<=amount;i++)
    {
        if(i%coins[0]==0)
            prev[i]=i/coins[0];
        else
            prev[i]=1e9;
    }
    for(int i=0;i<n;i++)
        prev[0]=0;
        
    //nested loops
    for(int i=1;i<n;i++)
    {
        for(int money=0;money<=amount;money++)
        {
            int notTake= 0 + prev[money];
            int take=INT_MAX;
            if(money>=coins[i])
                take=1+curr[money-coins[i]];
            curr[money]=min(notTake,take);
        }
        prev=curr;
    }
    int result=prev[amount];
    if(result>=1e9)
        return -1;
    return result;
}

int coinChange_1D_OPTIMIZATION(vector<int> &coins,int amount)
{
    if(amount==0)
        return 0;
    int n=coins.size();
    vector<int> prev(amount+1,0);

    //base conditions
    for(int i=0;i<=amount;i++)
    {
        if(i%coins[0]==0)
            prev[i]=i/coins[0];
        else
            prev[i]=1e9;
    }
    for(int i=0;i<n;i++)
        prev[0]=0;
        
    //nested loops
    for(int i=1;i<n;i++)
    {
        for(int money=0;money<=amount;money++)
        {
            int notTake= 0 + prev[money];
            int take=INT_MAX;
            if(money>=coins[i])
                take=1+prev[money-coins[i]];
            prev[money]=min(notTake,take);
        }
    }
    int result=prev[amount];
    if(result>=1e9)
        return -1;
    return result;
}

int main()
{
    
}