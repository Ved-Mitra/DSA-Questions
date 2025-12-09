#include <bits/stdc++.h>
using namespace std;

//any subset with sum k

//going from index n-1 --> 0
//dp--> size index*target constraints if target < 10^3
//dp --> [size+1][target + 1]
bool subsetSumK_M(vector<int> &arr,int k,int index,vector<vector<int>> &dp)
{
    //TC-O(N*target)
    //SC-O(N*target) + O(N)
    if(k==0)
        return true;
    if(index==0)
        return k==arr[0];
    if(dp[index][k]!=-1)
        return dp[index][k];
    bool notTake=subsetSumK_M(arr,k,index-1,dp);
    bool take=false;
    if(k>=arr[index])
        take=subsetSumK_M(arr,k-arr[index],index,dp);
    
    return dp[index][k]= (notTake | take);
}

bool subsetSumK_T(vector<int> &arr,int k)
{
    //TC-O(N*target)
    //SC-O(N*target)
    int n=arr.size();
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));

    //base condition
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    dp[0][arr[0]]=true;

    //nested loops
    for(int i=0;i<n;i++)
    {
        for(int target=1;target<=k;target++)
        {
            bool notTake= dp[i-1][target];
            bool take=false;
            if(target>=arr[i])
                take=dp[i-1][target-arr[i]];
            dp[i][target]= take | notTake;
        }
    }
    return dp[n-1][k];
}

bool subsetSumK_SC(vector<int> &arr,int k)
{
    //TC-O(N*target)
    //SC-O(target)
    int n=arr.size();
    vector<int> dp(k+1,false),curr(k+1,false);

    //base step
    dp[0]=true;
    dp[arr[0]]=true;
    for(int i=1;i<n;i++)
    {
        curr[0]=true;
        for(int target=1;target<=k;target)
        {
            bool notTake=dp[target];
            bool take=false;
            if(target>=arr[i])
                take=dp[target-arr[i]];
            curr[target]=take | notTake;
        }
        dp=curr;
    }
    return dp[k];
}

int main()
{
    
}