#include <bits/stdc++.h>
using namespace std;

// V.V.V. IMPORTANT 
//this problem states that either take the item or not take it

/*Q1. there are n items with each item has its own weight and value and the weight the theif chooses cannot exceeds bags limits you can take any item any number of times*/
//items -- > {weight,value}

int unboundedKnapsack_Memoization(vector<pair<int,int>> &items,int weight,int i,vector<vector<int>> &dp)
{
    if(i==0)
    {
        if(weight>=items[0].first)
            return items[0].second;
        return 0;
    }

    if(dp[i][weight]!=-1)
        return dp[i][weight];
    
    int notTake=0+unboundedKnapsack_Memoization(items,weight,i-1,dp);
    int take=0;
    if(weight>=items[i].first)
        take=items[i].second+unboundedKnapsack_Memoization(items,weight-items[i].first,i,dp);
    dp[i][weight]=max(take,notTake);
}

int unboundedKnapsack_Tabulation(vector<pair<int,int>> &items,int bag)
{
    int n=items.size();
    vector<vector<int>> dp(n,vector<int>(bag+1,0));
    
    //base condition
    for(int i=items[0].first;i<=bag;i++)
        dp[0][i]=items[0].second;

    for(int i=1;i<n;i++)
    {
        for(int weight=0;weight<=bag;weight++)
        {
            int notTake=0+dp[i-1][weight];
            int take=0;
            if(weight>=items[i].first)
                take=items[i].second+dp[i][weight-items[i].first];
            dp[i][weight]=max(take,notTake);
        }
    }
    return dp[n-1][bag];
}

int unboundedKnapsack_SC(vector<pair<int,int>> &items,int bag)
{
    int n=items.size();
    vector<int> prev(bag+1,0),curr(bag+1,0);
    
    //base condition
    for(int i=items[0].first;i<=bag;i++)
        prev[i]=items[0].second;

    for(int i=1;i<n;i++)
    {
        for(int weight=0;weight<=bag;weight++)
        {
            int notTake=0+prev[weight];
            int take=0;
            if(weight>=items[i].first)
                take=items[i].second+curr[weight-items[i].first];
            curr[weight]=max(take,notTake);
        }
        prev=curr;
    }
    return prev[bag];
}

int uboundedKnapsack_1D_OPTIMIZATION(vector<pair<int,int>> &items,int bag)
{
    int n=items.size();
    vector<int> dp(bag+1,0);
    
    //base condition
    for(int i=items[0].first;i<=bag;i++)
        dp[i]=items[0].second;

    for(int i=1;i<n;i++)
    {
        for(int weight=0;weight<=bag;weight++)
        {
            int notTake=0+dp[weight];
            int take=0;
            if(weight>=items[i].first)
                take=items[i].second+dp[weight-items[i].first];
            dp[weight]=max(take,notTake);
        }
    }
    return dp[bag];
}

int main()
{
    
}