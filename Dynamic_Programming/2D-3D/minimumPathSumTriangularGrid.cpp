#include <bits/stdc++.h>
using namespace std;

int minimumTotal_Memoization(vector<vector<int>> &triangle,int r,int c,vector<vector<int>> &dp)
{
    if(r==triangle.size()-1)
        return triangle[triangle.size()-1][c];
    if(dp[r][c]!=-1)
        return dp[r][c];
    int down=triangle[r][c]+minimumTotal_Memoization(triangle,r+1,c,dp);
    int dg=triangle[r][c]+minimumTotal_Memoization(triangle,r+1,c+1,dp);
    return dp[r][c]=min(down,dg);
}

int minimumTotal_Tabulation(vector<vector<int>> &triangle)
{
    vector<int> dp=triangle[triangle.size()-1];
    for(int i=triangle.size()-2;i>=0;i--)
    {
        vector<int> temp=triangle[i];
        for(int j=0;j<triangle[i].size();j++)
        {
            temp[j]+=min(dp[j],dp[j+1]);
        }
        dp=temp;
    }
    return dp[0];
}

int minimumTotal_SC(vector<vector<int>> &triangle)
{
    vector<int> dp=triangle[triangle.size()-1];
    for(int i=triangle.size()-2;i>=0;i--)
    {
        vector<int> temp=triangle[i];
        for(int j=0;j<triangle[i].size();j++)
        {
            temp[j]+=min(dp[j],dp[j+1]);
        }
        dp=temp;
    }
    return dp[0];
}


int main()
{

}