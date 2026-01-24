#include <bits/stdc++.h>
using namespace std;

//number of operations to multiple a matrix
/*
A=30*10
B=10*5
c=5*60

find ABC

(AB)C
operations=30*10*5 + 30*5*60=1500+9000=10500
A_row * Common * B_col

A(BC)
operations=10*5*60 + 30*10*60=3000+18000=21000

min way is (AB)C
*/

//Q. Given the N matrix dimensions, tel me the min cost to multiple them to a single matrix
//partitions are needed so partition DP


//PARTIOTIN DP NOTES

//1. Start with entire block/array f(i,j)
        /* (ABCD) --->  1. (AB)(CD)
                            ij  ij
                        2. (A)(BCD)
                            ij i j
                        3. (ABC)(D)
                            i j  ij
                        
                        i--> start point
                        j--> end point
        */
//2. Try all partitions (Run a loop to try all partition)
//3. Return the best 3 partitions
        // (AB)(CD) --> 2 partitions



int MCM_Memoization(vector<int> &arr,int i,int j,vector<vector<int>> &dp)
{
    /*
    arr=[10,20,30,40,50]
    A=10*20
    B=20*30
    C=30*40
    D=40*50

    Given dimensions of N matrices  
    
    [10,20,30,40,50]
        A, B, C, D
        i        j
        1        4

    f(1,4)--> returns the min multiplications to multiply matrix 1 --> matrx 4
    */

    //call from i=1,j=n-1

    //TC-O(N^3)
    //SC-O(N^2 + N)

    if(i==j)
        return 0;//no self multiplications operations
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int mini=1e9;

    for(int k=i;k<j;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j] + MCM_Memoization(arr,i,k,dp)+ MCM_Memoization(arr,k+1,j,dp);

        // partitions are (i,k) (k+1,j)
        //now to combine these 2 matrices is arr[i-1]*arr[k]*arr[j];
        mini=min(mini,steps);
    }
    return mini;
}

int MCM_Tabulation(vector<int> &arr)
{
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-1;i>=1;i--)
    {
        dp[i][i]=0;
        for(int j=i+1;j<n;j++)
        {
            int mini=1e9;
            for(int k=i;k<j;k++)
            {
                int steps=arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini=min(mini,steps);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
}


int main()
{
    
}