#include <bits/stdc++.h>
using namespace std;

// V.V.V. IMPORTANT 
//this problem states that either take the item or not take it

/*Q1. there are n items with each item has its own weight and value and the weight the theif chooses cannot exceeds bags limits*/
//items -- > {weight,value}



//cannot apply greddy approach of (value/weight) ratio

int maxWeight_Memoization(vector<pair<int,int>> &items,vector<vector<int>> &dp,int i,int weight)
{
    //dp --> [n][bag limit]
    if(i==0)
    {
        if(weight>=items[0].first)
            return items[0].second;
        return 0;
    }
    if(dp[i][weight]!=-1)
        return dp[i][weight];

    int notTake = 0+maxWeight_Memoization(items,dp,i-1,weight);
    int take=INT_MIN;
    if(weight>=items[i].first)
        take=items[i].second+maxWeight_Memoization(items,dp,i-1,weight-items[i].first);
    
    return dp[i][weight]=max(take,notTake);    
}

int maxWeight_Tabulation(vector<pair<int,int>> &items,int bag)
{
    int n=items.size();
    vector<vector<int>> dp(n,vector<int>(bag+1,0));
    
    //base condition
    for(int i=items[0].first;i<=bag;i++)
        dp[0][i]=items[0].second;
    
    //nested loops
    for(int i=1;i<n;i++)
    {
        for(int weight=0;weight<=bag;weight++)
        {
            int notTake=0+dp[i-1][weight];
            int take=INT_MIN;
            if(weight>=items[i].first)
                take=items[i].second+dp[i-1][weight-items[i].first];
            dp[i][weight]=max(take,notTake);
        }
    }
    return dp[n-1][bag];
}

int maxWeight_SC(vector<pair<int,int>> &items,int bag)
{
    int n=items.size();
    vector<int> prev(bag+1,0),curr(bag+1,0);
    
    //base condition
    for(int i=items[0].first;i<=bag;i++)
        prev[i]=items[0].second;
    
    //nested loops
    for(int i=1;i<n;i++)
    {
        for(int weight=0;weight<=bag;weight++)
        {
            int notTake=0+prev[weight];
            int take=INT_MIN;
            if(weight>=items[i].first)
                take=items[i].second+prev[weight-items[i].first];
            curr[weight]=max(take,notTake);
        }
        prev=curr;
    }
    return prev[bag];
}

int maxWeight_SC_1D_OPTIMIZATION(vector<pair<int,int>> &items,int bag)
{
    int n=items.size();
    vector<int> prev(bag+1,0);
    
    //base condition
    for(int i=items[0].first;i<=bag;i++)
        prev[i]=items[0].second;
    
    //nested loops
    for(int i=1;i<n;i++)
    {
        for(int weight=bag;weight>=0;weight--)
        {
            //we switched as value of weight-items[i].first is stored in starting half so no value is overwritten
            int notTake=0+prev[weight];
            int take=INT_MIN;
            if(weight>=items[i].first)
                take=items[i].second+prev[weight-items[i].first];
            prev[weight]=max(take,notTake);
        }
    }
    return prev[bag];
}


int main()
{

}