#include <bits/stdc++.h>
using namespace std;

int minimumTotal_Memoization(vector<vector<int>> &triangle,int r,int c)
{
    if(r>=triangle.size())  return 0;
    int down=triangle[r][c]+minimumTotal_Memoization(triangle,r+1,c);
    int diagonal=triangle[r][c]+minimumTotal_Memoization(triangle,r+1,c+1);
    return min(down,diagonal);
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