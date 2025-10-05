#include <bits/stdc++.h>
using namespace std;


int fibonacciSeries_Memozitation(int n,vector<int> &dp)
{
    //Memozitation
    //TC-O(n)
    //SC-O(n)+O(n)
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    dp[n]=fibonacciSeries_Memozitation(n-1,dp)+fibonacciSeries_Memozitation(n-2,dp);
    return dp[n];
}

int fibonacciSeries_Tabulation(int n)
{
    //TC-O(N)
    //SC-O(N)
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }

    //METHOD-2
    //TC-O(n)
    //SC-O(N)
    //use 3 variables
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    cout << fibonacciSeries_Memozitation(n,dp);


}