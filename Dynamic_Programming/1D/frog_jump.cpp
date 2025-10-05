#include <bits/stdc++.h>
using namespace std;


/*The frog is at ist starir of Nth staircase, the height[i] denotes the height(i+1)th stair, If the frog jumps from ith to jth stair then the energy lost by it is height(j-1)th - height(i-1)th stair. Your task is to find the minimum total energy used by the frog from 1st stair to the Nth stair*/


int frogJump_M(int index,vector<int> &height,vector<int> &dp)
{
    //TC-O(N)
    //SC-O(N)
    if(index==0)
        return 0;
    if(dp[index]!=-1)
        return dp[index];
    int left=frogJump_M(index-1,height,dp)+abs(height[index]-height[index-1]);
    int right=INT_MAX;
    if(index>1)
        right=frogJump_M(index-2,height,dp)+abs(height[index]-height[index-2]);
    return dp[index]=min(right,left);
}   

int frogJump_T(vector<int> &height)
{
    //TC-O(n)
    //SC-O(n)
    int n=height.size();
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int left=dp[i-1]+abs(height[i]-height[i-1]);
        int right=INT_MAX;
        if(i>1)
            right=dp[i-2]+abs(height[i]-height[i-2]);
        dp[i]=min(left,right);
    }
    return dp[n-1];
}

int frogJump_SC(vector<int> &height)
{
    //TC-O(N)
    //SC-O(1)
    int n=height.size();
    int l1=INT_MAX,l2=INT_MAX;
    l1=0;
    for(int i=1;i<n;i++)
    {
        int left=l1+abs(height[i]-height[i-1]);
        int right=INT_MAX;
        if(i>1)
            right=l2+abs(height[i]-height[i-2]);
        l2=l1;
        l1=min(left,right);
    }
    return l1;
}

int main()
{
    int n;
    cin  >> n;
    vector<int> dp(n+1,-1);

}