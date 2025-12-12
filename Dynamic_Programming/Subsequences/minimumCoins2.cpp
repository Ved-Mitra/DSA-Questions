#include <bits/stdc++.h>
using namespace std;

int coinChange2_Memoization(vector<int>& coins, int amount,int i,vector<vector<long long>> &dp)
{
    //vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    if(amount==0)
        return 1;
    if(i==0)
    {
        if(amount%coins[0]==0)
            return 1;
        return 0;
    }

    if(dp[i][amount]!=-1)
        return dp[i][amount];
    
    int notTake=coinChange2_Memoization(coins,amount,i-1,dp);
    int take=0;
    if(coins[i]<=amount)
        take=coinChange2_Memoization(coins,amount,i,dp);
    return dp[i][amount]=take+notTake;
}

int coinChange2_Tabulation(vector<int>& coins, int amount)
{
    if(amount==0)
        return 1;
    int n=coins.size();
    vector<vector<long long>> dp(n,vector<long long>(amount+1,0));

    //base conditions
    for(int i=0;i<=amount;i++)
    {
        if(i%coins[0]==0)
            dp[0][i]=1;;
    }
    for(int i=0;i<n;i++)
        dp[i][0]=1;
        
    //nested loops
    for(int i=1;i<n;i++)
    {
        for(int money=0;money<=amount;money++)
        {
            int notTake=dp[i-1][money];
            int take=0;
            if(money>=coins[i])
                take=dp[i][money-coins[i]];
            dp[i][money]=(long long)notTake+take;
        }
    }
    return dp[n-1][amount];
}

int coinChange2_SC(vector<int>& coins, int amount)
{
    if(amount==0)
        return 1;
    int n=coins.size();
    vector<long long> prev(amount+1,0),curr(amount+1,0);

    //base conditions
    for(int i=0;i<=amount;i++)
    {
        if(i%coins[0]==0)
            prev[i]=1;
    }
    for(int i=0;i<n;i++)
        prev[0]=1;
        
    //nested loops
    for(int i=1;i<n;i++)
    {
        for(int money=0;money<=amount;money++)
        {
            int notTake=prev[money];
            int take=0;
            if(money>=coins[i])
                take=curr[money-coins[i]];
            curr[money]=(long long)notTake+take;
        }
        prev=curr;
    }
    return prev[amount];
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
            prev[i]=1;
    }
    for(int i=0;i<n;i++)
        prev[0]=1;
        
    //nested loops
    for(int i=1;i<n;i++)
    {
        for(int money=0;money<=amount;money++)
        {
            int notTake=prev[money];
            int take=0;
            if(money>=coins[i])
                take=prev[money-coins[i]];
            prev[money]=notTake+take;
        }
    }
    return prev[amount];
}

int main()
{
    
}