#include <bits/stdc++.h>
using namespace std;

//STRIVER
int robHouse_Tabulation(vector<int> & arr)
{
    int n=arr.size();
    vector<int> dp(n,-1);
    //copy base case
    dp[0]=arr[0];
    int negative=0;
    for(int i=1;i<n;i++)
    {
        int take=arr[i];
        if(i>1)
            take+=dp[i-2];
        int nontake=0+dp[i-1];
        dp[i]=max(take,nontake);
    }
    return dp[n-1];
}

int robHouse_SC(vector<int> &arr)
{
    //TC-O(n)
    //SC-O(1)
    int n=arr.size();
    int prev1=arr[0];
    int prev2=0;
    for(int i=0;i<n;i++)
    {
        int take=arr[i]+prev2;
        int nontake=0+prev1;
        prev2=prev1;
        prev1=max(take,nontake);
    }
    return prev1;
}

// OPTIMAL - ME
int robHouse(vector<int> &nums, int index, vector<int> &dp)
{
    if (index >= nums.size())
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int money1 = nums[index] + robHouse(nums, index + 2, dp);
    int money2 = robHouse(nums, index + 1, dp);
    return dp[index] = max(money1, money2);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return robHouse(nums, 0, dp);
}

int main()
{

}