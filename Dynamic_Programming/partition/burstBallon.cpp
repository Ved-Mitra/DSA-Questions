#include <bits/stdc++.h>
using namespace std;


int recursiveHelper(vector<int> &nums,int i,int j,vector<vector<int>> &dp)
{
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    int maxx=INT_MIN;
    for(int index=i;index<=j;index++)
    {
        int cost= nums[i-1]*nums[index]*nums[j+1] + recursiveHelper(nums,i,index-1,dp) + recursiveHelper(nums,index+1,j,dp);
        maxx=max(maxx,cost);
    }
    return dp[i][j]=maxx;
}

int maxCoins_Memoization(vector<int> &nums)
{
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return recursiveHelper(nums,1,n-2,dp);
}

int maxCoins_Tabulation(vector<int> &nums)
{
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-2;i>=1;i--)
    {
        for(int j=1;j<=n-2;j++)
        {
            if(i>j)
                continue;
            int maxx=INT_MIN;
            for(int index=i;index<=j;index++)
            {
                int cost= nums[i-1]*nums[index]*nums[j+1] + dp[i][index-1] + dp[index+1][j];
                maxx=max(maxx,cost);
            }
            dp[i][j]=maxx;
        }
    }
    return dp[1][n-2];
}