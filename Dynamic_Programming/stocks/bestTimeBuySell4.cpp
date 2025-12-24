#include <bits/stdc++.h>
using namespace std;

int maxProfit_Memoization(vector<int> &prices,int i,bool buy,int transaction,vector<vector<vector<int>>> &dp,int n,int k)
{
    if(i==n || transaction==k)
        return 0;

    if(dp[i][buy][transaction]!=-1)
        return dp[i][buy][transaction];

    int profit=0;
    if(buy)
    {
        int take=-prices[i]+maxProfit_Memoization(prices,i+1,false,transaction,dp,n,k);//buy
        int notTake=0+maxProfit_Memoization(prices,i+1,true,transaction,dp,n,k);//not buy
        profit=max(take,notTake);
    }
    else
    {
        int take=prices[i]+maxProfit_Memoization(prices,i+1,true,transaction+1,dp,n,k);//sell
        //increasing transaction on selling
        int notTake=0+maxProfit_Memoization(prices,i+1,buy,transaction,dp,n,k);//not sell
        profit=max(take,notTake);
    }

    return dp[i][buy][transaction]=profit;
}

int maxProfit_Tabulation(int k, vector<int>& prices)
{
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)//buy
        {
            for(int transaction=0;transaction<k;transaction++)
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

int maxProfit_SC(int k, vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>> ahead(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)//buy
        {
            for(int transaction=0;transaction<k;transaction++)
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




int main()
{

}