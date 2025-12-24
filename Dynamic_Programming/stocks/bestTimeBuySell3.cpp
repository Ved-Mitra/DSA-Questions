#include <bits/stdc++.h>
using namespace std;

int maxProfit_Memoization(vector<int> &prices,int i,bool buy,int transaction,vector<vector<vector<int>>> &dp,int n)
{
    if(i==n || transaction==2)
        return 0;

    if(dp[i][buy][transaction]!=-1)
        return dp[i][buy][transaction];

    int profit=0;
    if(buy)
    {
        int take=-prices[i]+maxProfit_Memoization(prices,i+1,false,transaction,dp,n);//buy
        int notTake=0+maxProfit_Memoization(prices,i+1,true,transaction,dp,n);//not buy
        profit=max(take,notTake);
    }
    else
    {
        int take=prices[i]+maxProfit_Memoization(prices,i+1,true,transaction+1,dp,n);//sell
        //increasing transaction on selling
        int notTake=0+maxProfit_Memoization(prices,i+1,buy,transaction,dp,n);//not sell
        profit=max(take,notTake);
    }

    return dp[i][buy][transaction]=profit;
}

int maxProfit_tabulation(vector<int> &prices)
{
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)//buy
        {
            for(int transaction=0;transaction<2;transaction++)
            {
                int profit=0;
                if(j)
                {
                    int buy=-prices[i]+dp[i+1][0][transaction];
                    int notBuy=dp[i+1][1][transaction];
                    profit=max(buy,notBuy);
                }
                else
                {
                    int sell=prices[i]+dp[i+1][1][transaction+1];
                    int notSell=dp[i+1][0][transaction];
                    profit=max(sell,notSell);
                }
                dp[i][j][transaction]=profit;
            }
        }
    }
    return dp[0][1][0];
}

int maxProfit_SC(vector<int> &prices)
{
    int n=prices.size();
    vector<vector<int>> ahead(2,vector<int>(3,0)),curr(2,vector<int>(3,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)//buy
        {
            for(int transaction=0;transaction<2;transaction++)
            {
                int profit=0;
                if(j)
                {
                    int buy=-prices[i]+ahead[0][transaction];
                    int notBuy=ahead[1][transaction];
                    profit=max(buy,notBuy);
                }
                else
                {
                    int sell=prices[i]+ahead[1][transaction+1];
                    int notSell=ahead[0][transaction];
                    profit=max(sell,notSell);
                }
                curr[j][transaction]=profit;
            }
        }
        ahead=curr;
    }
    return ahead[1][0];
}

int maxProfit_Memoization_2(vector<int> &prices,int i,int transaction,int n,vector<vector<int>> &dp)
{
    //different dp
    //dp[n][4] --> for 4: Buy Sell Buy Sell
    //transaction number

    if(i==n || transaction==4)
        return 0;

    if(dp[i][transaction]!=-1)
        return dp[i][transaction];

    int profit=0;
    if(transaction%2==0)//buy
    {
        int buy=-prices[i]+maxProfit_Memoization_2(prices,i+1,transaction+1,n,dp);
        int notBuy=0+maxProfit_Memoization_2(prices,i+1,transaction,n,dp);;
        profit=max(buy,notBuy);
    }
    else //sell
    {
        int sell=prices[i]+maxProfit_Memoization_2(prices,i+1,transaction+1,n,dp);
        int notSell=0+maxProfit_Memoization_2(prices,i+1,transaction,n,dp);
        profit=max(sell,notSell);
    }

    return dp[i][transaction]=profit;
}






int main()
{

}