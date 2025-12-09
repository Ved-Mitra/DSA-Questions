#include <bits/stdc++.h>
using namespace std;

//any 2 subset with equal sum
//here   k = target = (sum of arr /2)

//going from index n-1 --> 0
//dp--> size index*target constraints if target < 10^3
//dp --> [size+1][target + 1]
bool canPartition_M(vector<int> &arr,int k,int index,vector<vector<int>> &dp)
{
    //TC-O(N*target)
    //SC-O(N*target) + O(N)
    if(k==0)
        return true;
    if(index==0)
        return k==arr[0];
    if(dp[index][k]!=-1)
        return dp[index][k];
    bool notTake=canPartition_M(arr,k,index-1,dp);
    bool take=false;
    if(k>=arr[index])
        take=canPartition_M(arr,k-arr[index],index,dp);
    
    return dp[index][k]= (notTake | take);
}

bool canPartition_T(vector<int> &arr)
{
    //TC-O(N*target)
    //SC-O(N*target)
    int n=arr.size();
    int k=accumulate(arr.begin(),arr.end(),0)/2;
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

bool canPartition_SC(vector<int> &arr)
{
    //TC-O(N*target)
    //SC-O(target)
    int n=arr.size();
    int k=accumulate(arr.begin(),arr.end(),0)/2;
    vector<int> dp(k+1,false),curr(k+1,false);

    //base step
    dp[0]=true;
    if(arr[0]<=k)
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