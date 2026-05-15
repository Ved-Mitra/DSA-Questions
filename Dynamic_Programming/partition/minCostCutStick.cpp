#include <bits/stdc++.h>
using namespace std;

int recursiveHelper(vector<int> &cuts,int i,int j,vector<vector<int>> &dp)
{
    //TC-O(N^3)
    //SC-O(N^2)

    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    int mini=1e9;
    for(int index=i+1;index<j;index++)
    {
        int cost= (cuts[j]-cuts[i])+recursiveHelper(cuts,i,index,dp)+recursiveHelper(cuts,index,j,dp);
        mini=min(mini,cost);
    }

    return dp[i][j]=mini;
}
int minCost_Memoization(int n,vector<int> &cuts)
{
    sort(cuts.begin(),cuts.end());
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    int c=cuts.size();
    vector<vector<int>> dp(c,vector<int>(c,-1));
    return recursiveHelper(cuts,0,c-1,dp);
}

int minCost_Tabulation(int n,vector<int> &cuts)
{
    sort(cuts.begin(),cuts.end());
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    int c=cuts.size();
    vector<vector<int>> dp(c,vector<int>(c,0));
    for(int i=c-1;i>=0;i--)
    {
        for(int j=i+2;j<c;j++)
        {
            int mini=1e9;
            for(int index=i+1;index<j;index++)
            {
                int cost=(cuts[j]-cuts[i])+dp[i][index]+dp[index][j];
                mini=min(mini,cost);
            }
            dp[i][j]=mini;
        }
    }
    return dp[0][c-1];
}

int recursiveHelper_striver(vector<int> &cuts,int i,int j,vector<vector<int>> &dp)
{
    //TC-O(N^3)
    //SC-O(N^2)

    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    int mini=1e9;
    for(int index=i;index<=j;index++)
    {
        int cost= (cuts[j+1]-cuts[i-1])+recursiveHelper(cuts,i,index-1,dp)+recursiveHelper(cuts,index+1,j,dp);
        mini=min(mini,cost);
    }

    return dp[i][j]=mini;
}
int minCost_Memoization_Striver(int n,vector<int> &cuts)
{
    sort(cuts.begin(),cuts.end());
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    int c=cuts.size();
    vector<vector<int>> dp(c,vector<int>(c,-1));
    return recursiveHelper_striver(cuts,1,c-2,dp);
}

int minCost_Tabulation_Striver(vector<int> &cuts,int n)
{
    sort(cuts.begin(),cuts.end());
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    int c=cuts.size();
    vector<vector<int>> dp(c,vector<int>(c,0));
    for(int i=c-2;i>=1;i--)
    {
        for(int j=1;j<=c-2;j++)
        {
            if(i>j)
                continue;
            int mini=1e9;
            for(int index=i;index<=j;index++)
            {
                int cost=(cuts[j+1]-cuts[i-1])+dp[i][index-1]+dp[index+1][j];
                mini=min(mini,cost);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][c-2];
}

int main()
{

}