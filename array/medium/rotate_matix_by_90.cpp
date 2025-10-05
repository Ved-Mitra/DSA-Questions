#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the value of n: ";
    int n;
    cin >> n;
    vector< vector<int> > arr;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> arr[i][j];
        }
    }

    //BRUTE
    /*
     i  j    j  n-1-i
    [0][0]->[0][3]
    [0][1]->[1][3]    
    */
    int ans[n][n];
    //TC-O(N^2)
    //SC-O(N)
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[j][n-1-i]=arr[i][j];
        }
    }

    //OPTIMAL
    //TC-O()
    //SC-O()
    //transpose the matrix first
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
    //reverse every row
    for(int i=0;i<n;i++)
    {
        reverse(arr[i],arr[i]+n);
    }
}