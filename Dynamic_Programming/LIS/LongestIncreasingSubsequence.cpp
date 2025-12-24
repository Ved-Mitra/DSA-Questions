#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS_Memoization(vector<int> &nums,int i,int prev_index,vector<vector<int>> &dp,int n)
{
    //prev_index-->denotes the prev index in subsequence

    //TC-O(N*N)
    //SC-O(N*N) + O(N)
    if(i==n)
        return 0;

    if(dp[i][prev_index+1]!=-1)
        return dp[i][prev_index+1];

    int notTake=0+lengthOfLIS_Memoization(nums,i+1,prev_index,dp,n);
    int take=0;
    if(prev_index==-1 || nums[i]>nums[prev_index])
        take=1+lengthOfLIS_Memoization(nums,i+1,i,dp,n);

    return dp[i][prev_index+1]=max(take,notTake);
}   

int lengthOfLIS_Tabulation(vector<int> &nums)
{
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=-1;j--)//prev
        {
            int notTake=0+dp[i+1][j+1];
            int take=0;
            if(j==-1 || nums[i]>nums[j])
                take=1+dp[i+1][i+1];
            dp[i][j+1]=max(take,notTake);
        }
    }
    return dp[0][0]; // dp[0][-1+1]
}

int lengthOfLIS_SC(vector<int> &nums)
{
    int n=nums.size();
    vector<int> ahead(n+1,0),curr(n+1,0);

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=-1;j--)//prev
        {
            int notTake=0+ahead[j+1];
            int take=0;
            if(j==-1 || nums[i]>nums[j])
                take=1+ahead[i+1];
            curr[j+1]=max(take,notTake);
        }
        ahead=curr;
    }
    return ahead[0];
}


int main()
{

}