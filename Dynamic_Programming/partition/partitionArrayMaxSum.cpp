#include <bits/stdc++.h>
using namespace std;

//Done with the concept of FORWARD PARTITION (explained in palindromePartitioning2.cpp)

//this is not optimized solution and highly complicated
int recursiveHelper(vector<int> &arr,int k,int i,int j,vector<vector<int>> &dp)
{
    if(i>j)
        return 0;
    if(i==j)
        return arr[i];
    
    if(dp[i][j]!=-1)
        return dp[i][j];

    int maxSum=INT_MIN;
    deque<int> dq;
    for(int index=i;index<=j;index++)
    {
        if(!dq.empty() && dq.front()<=index-k)
            dq.pop_front();
        while(!dq.empty() && arr[dq.back()]<=arr[index])
            dq.pop_back();
        dq.push_back(index);
        maxSum=max(maxSum,arr[dq.front()]*(min(k,index-i+1)) + recursiveHelper(arr,k,index+1,j,dp) + recursiveHelper(arr,k,i,max(i-1,index-k),dp));
    }

    return dp[i][j]=maxSum;
}
int maxSumAfterPartitioning_Memoization_Unoptimized(vector<int> &arr,int k)
{
    int n=arr.size();
    if(k==1)
        return accumulate(arr.begin(),arr.end(),0);
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return recursiveHelper(arr,k,0,n-1,dp);
}



int recursiveHelper(vector<int> &arr,int k ,int i,vector<int> &dp)
{
    if(i>=arr.size())
        return 0;

    if(dp[i]!=-1)
        return dp[i];

    int maxSum=INT_MIN,maxEl=INT_MIN;
    for(int len=0;len<k && len+i<arr.size();len++)
    {
        maxEl=max(maxEl,arr[i+len]);
        maxSum=max(maxSum,maxEl*(len+1) + recursiveHelper(arr,k,i+len+1,dp));
    }
    return dp[i]=maxSum;
}

int maxSumAfterPartitioning_Memozation(vector<int> &arr,int k)
{
    int n=arr.size();
    vector<int> dp(n,-1);
    return recursiveHelper(arr,k,0,dp);
}


int maxSumAfterPartitioning_Tabulation(vector<int> &arr,int k)
{
    int n=arr.size();
    vector<int> dp(n+1,0);
    for(int i=n-1;i>=0;i--)
    {
        int maxSum=INT_MIN,maxEl=INT_MIN;
        for(int len=0;len<k && len+i<arr.size();len++)
        {
            maxEl=max(maxEl,arr[i+len]);
            maxSum=max(maxSum,maxEl*(len+1) + dp[i+len+1]);
        }
        dp[i]=maxSum;
    }
    return dp[0];
}


int main()
{
    
}