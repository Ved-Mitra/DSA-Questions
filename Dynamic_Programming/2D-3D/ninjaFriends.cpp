#include <bits/stdc++.h>
using namespace std;

/*Based on the image provided, here is the text transcription:

Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.

Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, 'C' - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.

If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the 'GRID'.

Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.*/

int recursiveHelper(vector<vector<int>> &grid,int r,int A_c,int B_c,vector<vector<vector<int>>> &dp,int m,int n)
{
    //TC-O(9* m * n * n)
    //SC-O(n) + dp
    //row remains same just the colum changes
    if(A_c<0 || A_c>=n || B_c<0 || B_c>=n || r<0 || r>=m)
        return -1e9;

    if(dp[r][A_c][B_c]!=-1)
        return dp[r][A_c][B_c];

    if(r==m-1)
    {
        if(A_c==B_c)
            return grid[r][A_c];
        else
            return grid[r][A_c]+grid[r][B_c];
    }

    int maxi=INT_MIN;
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            maxi=max(maxi,recursiveHelper(grid,r+1,A_c+i,B_c+j,dp,m,n));

    if(A_c!=B_c)
        maxi+=(grid[r][A_c]+grid[r][B_c]);
    else
        maxi+=grid[r][A_c];

    return dp[r][A_c][B_c]=maxi;
}
int maximumChocolates_Memoization(vector<vector<int>> &grid)
{
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
    return recursiveHelper(grid,0,0,n-1,dp,m,n);
}

int maximumChocolates_Tabulation(vector<vector<int>> &grid)
{
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
    //base case
    for(int j1=0;j1<n;j1++)
    {
        for(int j2=0;j2<n;j2++)
        {
            if(j1==j2)
                dp[n-1][j1][j2]=grid[n-1][j1];
            else
                dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
        }
    }

    for(int i=m-2;i>=0;i--)
    {
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                int maxi=INT_MIN;
                for(int dj1=-1;dj1<=1;dj1++)
                    for(int dj2=-1;dj2<=1;dj2++)
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m)
                            maxi=max(maxi,dp[i+1][j1+dj1][j2+dj2]);

                if(j1!=j2)
                    maxi+=(grid[i][j1]+grid[i][j2]);
                else
                    maxi+=grid[i][j1];

                dp[i][j1][j2]=maxi;
            }
        }
    }
    return dp[0][0][n-1];
}

int maximumChocolates_SC(vector<vector<int>> &grid)
{
    //2D-->1D
    //3D-->2D

    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> prev(n,vector<int>(n,-1));
    vector<vector<int>>curr(n,vector<int>(n,-1));
    //base condition
    for(int j1=0;j1<n;j1++)
        for(int j2=0;j2<n;j2++)
        {
            if(j1==j2)
                prev[j1][j2]=grid[m-1][j1];
            else
                prev[j1][j2]=grid[m-1][j1]+grid[m-1][j2];
        }
    
    for(int i=m-2;i>=0;i--)
    {
        for(int j1=0;j1<n;j1++)
        {
            for(int j2=0;j2<n;j2++)
            {
                int maxi=INT_MIN;
                for(int dj1=-1;dj1<=1;dj1++)
                    for(int dj2=-1;dj2<=1;dj2++)
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m)
                            maxi=max(maxi,prev[j1+dj1][j2+dj2]);

                if(j1!=j2)
                    maxi+=(grid[i][j1]+grid[i][j2]);
                else
                    maxi+=grid[i][j1];

                curr[j1][j2]=maxi;
            }
        }
        prev=curr;
    }

    return prev[0][n-1];
}


int main()
{

}