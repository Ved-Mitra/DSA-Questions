#include <bits/stdc++.h>
using namespace std;

int numberOfLongestIncreasingSubsequence(vector<int> &nums)
{
    int n=nums.size();
    vector<int> dp(n,1),cnt(n,1);
    int maxi=1;
    for(int i=0;i<n;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            if(nums[i]>nums[prev] && dp[prev]+1>dp[i])
            {
                dp[i]=dp[prev]+1;
                cnt[i]=cnt[prev]; //inherit
            }
            else if(nums[i]>nums[prev] && dp[prev]+1==dp[i])
                cnt[i]+=cnt[prev]; //add
                
        }
        maxi=max(maxi,dp[i]);
    }
    int nos=0;
    for(int i=0;i<n;i++)
        if(dp[i]==maxi)
            nos+=cnt[i];

    return nos;
}








int main()
{

}