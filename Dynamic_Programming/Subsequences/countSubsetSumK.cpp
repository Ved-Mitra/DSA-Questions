#include <bits/stdc++.h>
using namespace std;

//if nums includes 0 then copute the number of zeroes
//let zeroes be n and number of subset with sum k =m
//total answer= (2^n)*m


int cntSubsetSumK_Memoization(vector<int> &nums,vector<vector<int>> &dp,int k,int i)
{
    //if no zeroes in array
    // if(k==0)
    //     return 1;
    // if(i==0)
    //     return nums[0]==k;

    //to account for zeroes
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
    
    int take=cntSubsetSumK_Memoization(nums,dp,k,i-1);
    int notTake=0;
    if(nums[i]<=k)
        notTake=cntSubsetSumK_Memoization(nums,dp,k-nums[i],i);
    
    return dp[i][k]=take+notTake;
}

int cntSubsetSumK_Tabulation(vector<int> &nums,int k)
{
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    
    //base step
    for(int i=0;i<n;i++)
        dp[i][0]=1;
    if(nums[0]<=k)
        dp[0][nums[0]]=1;
    
    for(int i=1;i<n;i++)
    {
        for(int target=1;target<=k;target++)
        {
            int notTake=dp[i-1][target];
            int take=0;
            if(nums[i]<=target)
                take+=dp[i-1][target-nums[i]];
            dp[i][target]=take+notTake;
        }
    }
    return dp[n-1][k];
}

int cntSubsetSumK_SC(vector<int> &nums,int k)
{
    int n=nums.size();
    vector<int> prev(k+1,0),curr(k+1,0);
    
    //base step
    prev[0]=1;
    if(nums[0]<=k)
        prev[nums[0]]=1;
    
    for(int i=1;i<n;i++)
    {
        curr[0]=1;
        for(int target=1;target<=k;target++)
        {
            int notTake=prev[target];
            int take=0;
            if(nums[i]<=target)
                take+=prev[target-nums[i]];
            curr[target]=take+notTake;
        }
        prev=curr;
    }
    return prev[k];
}





int main()
{

}