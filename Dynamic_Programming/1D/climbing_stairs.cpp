#include <bits/stdc++.h>
using namespace std;

/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/


int helper(int n,vector<int> &dp)
{
    if(n<0)
        return 0;
    if(n<=1)
        return dp[n]=1;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=helper(n-1,dp)+helper(n-2,dp);
}
//for tabulation and space optimized solution refer to fibonacci question as thses questions are same


int climbingStairs(int n)
{
    vector<int> dp(n+1,-1);
    return helper(n,dp);
}


int main()
{

}