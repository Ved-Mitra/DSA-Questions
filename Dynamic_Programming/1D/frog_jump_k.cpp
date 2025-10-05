#include <bits/stdc++.h>
using namespace std;

int frogJump_K_Memozitation(int k,int index,vector<int> &height,vector<int> &dp)
{
    //TC-O(N*k)
    //SC-O(N)+O(N)
    if(index==0)
        return 0;
    if(dp[index]!=-1)
        return dp[index];
    int minn=INT_MAX;
    for(int j=1;j<=k;j++)
    {
        if(index-j>=0)
        {
            int val=frogJump_K_Memozitation(k,index-j,height,dp)+abs(height[index]-height[index-j]);
            minn=min(minn,val);
        }
        else
            break;
    }
    return dp[index]=minn;
}

int frogJump_K_Tabulation(vector<int> &height,int k)
{
    //TC-O(N*k)
    //SC-O(N)
    int n=height.size();
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int minn=INT_MAX;
        for(int j=1;j<=k && i-j>=0;j++)
        {
            int val=dp[i-j] + abs(height[i]-height[i-j]);
            minn=min(minn,val);
        }
        dp[i]=minn;
    }
    return dp[n-1];
}


int frogJump_K_SC(int k,vector<int> &height)
{
    //TC-O(N*k)
    //SC-O(k)
    int n=height.size();
    vector<int> dp(k,-1);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int minn=INT_MAX;
        for(int j=1;j<=k && i-j>=0;j++)
        {
            int val=dp[j-1] + abs(height[i]-height[i-j]);
            minn=min(minn,val);
        }
        for(int i=0;i<k-1;i++)
        {
            dp[i]=dp[i+1];
        }
        dp[k-1]=minn;
    }
    return dp[n-1];
}


int main()
{

}