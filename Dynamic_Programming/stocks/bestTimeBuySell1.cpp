#include <bits/stdc++.h>
using namespace std;


int maxProfit(vector<int> &prices)
{
    int n=prices.size();
    int profit=0;
    int buy=prices[0];
    for(int i=0;i<n;i++)
    {
        int cost=prices[i]-buy;
        buy=min(buy,prices[i]);
        profit=max(profit,cost);
    }
    return profit;
}



int main()
{

}