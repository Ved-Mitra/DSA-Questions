#include <bits/stdc++.h>
using namespace std;

//the memoization, Tabulation and SC is same as longest increasing subsequence but only valid to get the number but here we want the sequence so we are following this

vector<int> LargestDivisibleSubset(vector<int> &nums)
{
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<int> dp(n,1),hash(n);
    for(int i=0;i<n;i++)
        hash[i]=i;

    int lastIndex=0,maxi=1;
    for(int i=0;i<n;i++)
    {
        for(int prev_index=0;prev_index<i;prev_index++)
        {
            if(nums[i]%nums[prev_index]==0 && dp[prev_index]+1>dp[i])
            {
                dp[i]=1+dp[prev_index];
                hash[i]=prev_index;
            }
        }
        if(maxi<dp[i])
        {
            maxi=dp[i];
            lastIndex=i;
        }
    }

    vector<int> ans;
    while(hash[lastIndex]!=lastIndex)
    {
        ans.push_back(nums[lastIndex]);
        lastIndex=hash[lastIndex];
    }
    ans.push_back(nums[lastIndex]);
    //reverse(ans.begin(),ans.end()); //this lines doesn't matters as order is not significant in subset
    return ans;
}


int main()
{

}