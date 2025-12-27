#include <bits/stdc++.h>
using namespace std;

//longest Biotonic sequence --> increasing + decreasing 
//example:
//1. [1,2,4,6,8,5,1]
//2. [1,2,3,4,5,6]
//3. [9,6,3,1]
//can contain both increasing and decreasing or only one

int largestBiotonicSuqsequence(vector<int> &nums)
{
    int n=nums.size();
    vector<int> dp1,dp2;
    dp1=largestIncreasingSubsequence(nums);
    reverse(nums.begin(),nums.end());
    dp2=largestIncreasingSubsequence(nums);
    int maxi=1;
    for(int i=0;i<n;i++)
        maxi=max(maxi,dp1[i]+dp2[i]-1); // -1 --> to remove the duplicate elements that is the ith element
    return maxi;
}

vector<int> largestIncreasingSubsequence(vector<int>&nums)
{
    int n=nums.size();
    vector<int> dp(n,1);
    for(int i=0;i<n;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            if(nums[i]>nums[prev])
                dp[i]=max(dp[i],1+dp[prev]);
        }
    }
    return dp;
}





int main()
{

}