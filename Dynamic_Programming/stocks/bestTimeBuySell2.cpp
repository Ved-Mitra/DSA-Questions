#include <bits/stdc++.h>
using namespace std;

int maxProfit_Memoization(vector<int> &prices,int i,bool buy,vector<vector<int>> &dp,int n)
{
    if(i==n)
        return 0;

    if(dp[i][buy]!=-1)
        return dp[i][buy];

    int profit=0;
    if(buy)
    {
        int take=-prices[i]+maxProfit_Memoization(prices,i+1,false,dp,n);//buy
        int notTake=0+maxProfit_Memoization(prices,i+1,true,dp,n);//not buy
        profit=max(take,notTake);
    }
    else
    {
        int take=prices[i]+maxProfit_Memoization(prices,i+1,true,dp,n);//sell
        int notTake=0+maxProfit_Memoization(prices,i+1,buy,dp,n);//not sell
        profit=max(take,notTake);
    }

    return dp[i][buy]=profit;
}

int maxProfit_Tabulation(vector<int> &prices)
{
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j>=0;j--)
        {
            int profit=0;
            if(j)
            {
                int buy=-prices[i]+dp[i+1][0];
                int notBuy=dp[i+1][1];
                profit=max(buy,notBuy);
            }
            else
            {
                int sell=prices[i]+dp[i+1][1];
                int notSell=dp[i+1][0];
                profit=max(sell,notSell);
            }
            dp[i][j]=profit;
        }
    }

    return dp[0][1];
}

int maxProfit_SC(vector<int> &prices)
{
    int n=prices.size();
    vector<int> ahead(2,0),curr(2,0);

    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j>=0;j--)
        {
            int profit=0;
            if(j)
            {
                int buy=-prices[i]+ahead[0];
                int notBuy=ahead[1];
                profit=max(buy,notBuy);
            }
            else
            {
                int sell=prices[i]+ahead[1];
                int notSell=ahead[0];
                profit=max(sell,notSell);
            }
            curr[j]=profit;
        }
        ahead=curr;
    }

    return ahead[1];
}





int main()
{
    
}