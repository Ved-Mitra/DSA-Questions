#include <bits/stdc++.h>
using namespace std;

//calculate the number of subset when we divide array into 2 partition(possibly empty) such that number of elementsclear of S1 >= sum of S2 and diff of S1 and S2 is equal to d

//here S1+S2=arrSum
// S1-S2=D
//S1=arrSum-S2
//arrSum-2*S2=D
//S2=(arrSum-D)/2

//therefore, k =(arrSum-D)/2
//conditions:
//1. arrSum-D>=0
//2. arrSum-D should be even


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

int cntParitionDiffK_Memoization(vector<int> &nums,int d)
{
    int n=nums.size();
    int arrSum=0;
    for(int i=0;i<n;i++)    
        arrSum+=nums[i];
    if(arrSum-d<0 || (arrSum-d)%2==1)
        return 0;
    int k=(arrSum-d)/2;
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return recursiveHelper(nums,k,n-1,dp);
}

int cntParitionDiffK_Tabulation(vector<int> &nums,int d)
{
    int n=nums.size();
    int arrSum=0;
    for(int i=0;i<n;i++)    
        arrSum+=nums[i];
    if(arrSum-d<0 || (arrSum-d)%2==1)
        return 0;
    int k=(arrSum-d)/2;
    vector<vector<int>> dp(n,vector<int>(k+1,-1));

    //base condition
    for(int i=0;i<n;i++)
        dp[i][0]=1;
    if(k>=nums[0])
        dp[0][nums[0]]=1;

    for(int i=1;i<n;i++)
    {
        for(int target=1;target<=k;target++)
        {
            int take=dp[i-1][target];
            int notTake=0;
            if(target>=nums[i])
                notTake=dp[i-1][target];
            dp[i][target]=take+notTake;
        }
    }
    return dp[n-1][k];
}

int cntParitionDiffK_SC(vector<int> &nums,int d)
{
    int n=nums.size();
    int arrSum=0;
    for(int i=0;i<n;i++)    
        arrSum+=nums[i];
    if(arrSum-d<0 || (arrSum-d)%2==1)
        return 0;
    int k=(arrSum-d)/2;
    vector<int> prev(k+1,-1),curr(k+1,-1);

    //base condition
    prev[0]=1;
    if(k>=nums[0])
        prev[nums[0]]=1;

    for(int i=1;i<n;i++)
    {
        for(int target=1;target<=k;target++)
        {
            int take=prev[target];
            int notTake=0;
            if(target>=nums[i])
                notTake=prev[target];
            curr[target]=take+notTake;
        }
        prev=curr;
    }
    return prev[k];
}

int main()
{
    
}