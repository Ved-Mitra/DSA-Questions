#include <bits/stdc++.h>
using namespace std;

//just like cntPartitionDiff.cpp
//divide in 2 partitions S1-S2=D
//target=S2=(arrSum-D)/2;
//but we need to look for S1
//k=(arrSum+D)/2


int recursiveHelper(vector<int> &nums,int k,int i,vector<vector<int>> &dp)
{
    if(i==0)
    {
        if(k==0 && nums[0]==0)
            return 2;
        if(k==0 || nums[0]==k)
            return 1;
        return 0;
    }
    if(dp[i][k]!=-1)
        return dp[i][k];

    int notTake=recursiveHelper(nums,k,i-1,dp);
    int take=0;
    if(k>=nums[i])
        take=recursiveHelper(nums,k-nums[i],i-1,dp);
    return dp[i][k]=take + notTake;
}
int findTargetSumWays_Memoization(vector<int>& nums, int target)
{
    int n=nums.size();
    int arrSum=0;
    for(int i=0;i<n;i++)
        arrSum+=nums[i];
    if(arrSum-target<0 || (arrSum-target)%2==1)
        return 0;
    int k=(arrSum-target)/2;
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return recursiveHelper(nums,k,n-1,dp);
}

int findTargetSumWays_Tabulation(vector<int>& nums, int target)
{
    int n=nums.size();
    int arrSum=0;
    for(int i=0;i<n;i++)    
        arrSum+=nums[i];
    if(arrSum-target<0 || (arrSum-target)%2==1)
        return 0;
    int k=(arrSum-target)/2;
    vector<vector<int>> dp(n,vector<int>(k+1,0));

    //base condition
    if(nums[0]==0)
        dp[0][0]=2;
    else
        dp[0][0]=1;
    if(k>=nums[0] && nums[0]!=0)
        dp[0][nums[0]]=1;

    for(int i=1;i<n;i++)
    {
        for(int target=1;target<=k;target++)
        {
            int notTake=dp[i-1][target];
            int take=0;
            if(target>=nums[i])
                take=dp[i-1][target-nums[i]];
            dp[i][target]=take+notTake;
        }
    }
    return dp[n-1][k];
}

int findTargetSumWays_SC(vector<int>& nums, int target)
{
    int n=nums.size();
    int arrSum=0;
    for(int i=0;i<n;i++)    
        arrSum+=nums[i];
    if(arrSum-target<0 || (arrSum-target)%2==1)
        return 0;
    int k=(arrSum-target)/2;
    vector<int> prev(k+1,0),curr(k+1,0);

    //base condition
    if(nums[0]==0)
        prev[0]=2;
    else
        prev[0]=1;
    if(k>=nums[0] && nums[0]!=0)
        prev[nums[0]]=1;

    for(int i=1;i<n;i++)
    {
        curr[0]=1;
        for(int target=1;target<=k;target++)
        {
            int notTake=prev[target];
            int take=0;
            if(target>=nums[i])
                take=prev[target-nums[i]];
            curr[target]=take+notTake;
        }
        prev=curr;
    }
    return prev[k];
}


int main()
{

}