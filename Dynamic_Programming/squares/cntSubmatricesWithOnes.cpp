#include <bits/stdc++.h>
using namespace std;

//IN COUNT PROBLEMS TABULATION IS INTUTIVE
int countSquares(vector<vector<int>> &matrix)
{
    //dp[i][j] --> how many squares end at (i,j)
    int m=matrix.size();
    int n=matrix[0].size();

    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
    {
        if(matrix[i][0]==1)
            dp[i][0]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(matrix[0][i]==1)
            dp[0][i]=1;
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
        }
    }
    int cnt=0;
    for(int i=0;i<m;i++)
        cnt+=accumulate(dp[i].begin(),dp[i].end(),0);
    return cnt;
}


int main()
{

}