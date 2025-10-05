#include<bits/stdc++.h>
using namespace std;

/*
Q. Find the next permutation(next permutation after arranging all permutation in ascending order) of inputed array
*/
void markRow(int **arr,int n,int i)
{
    for(int j=0;j<n;j++)
    {
        if(arr[i][j]!=0)
            arr[i][j]=-1;
    }
}
void markColumn(int **arr,int m,int j)
{
    for(int i=0;i<m;i++)
    {
        if(arr[i][j]!=0)
            arr[i][j]=-1;
    }
}
int main()
{
    int n,m;
    cout << "Enter the size of array: " ;
    cin >> n >> m;
    int arr[n][m];
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> arr[i][j];

    //BRUTE
    //TC-O(N^3)
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                markRow(arr,n,i);
                markColumn(arr,m,j);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==-1)
                arr[i][j]==0;
        }
    }
    
    //BETTER
    int col[m]={0};
    int row[n]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(row[i]==1 || col[j]==1)
                arr[i][j]=0;
        }
    }

    //OPTIMAL
    //int col[m]={0};  --> matrix[0][..]
    //int row[n]={0};  --> matrix[..][0]
    //TC-O(M*N)
    //SC-O(1)
    int col0=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                //mark the ith row
                arr[i][0]=0;
                //mark the jth column
                if(j!=0)
                    arr[0][j]=0;
                else
                    col0=0;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]!=0)
            {
                //check for row and column
                if(arr[0][j]==0 || arr[i][0]==0)
                    arr[i][j]=0;
            }
        }
    }
    if(arr[0][0]==0)
    {
        for(int j=0;j<m;j++)
        {
            arr[0][j]=0;
        }
    }
    if(col0==0)
    {
        for(int i=0;i<n;i++)
            arr[i][0]=0;
    }
}