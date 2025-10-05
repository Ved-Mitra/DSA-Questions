#include<bits/stdc++.h>
using namespace std;

/*
Q. return search result in 2D array
*/
bool search1_sol1(vector<vector<int>> matrix,int target)
{
    int m=matrix.size();
    int n=matrix[0].size();
    int row=-1;
    if(m==1)
        row=0;
    else if(target<matrix[1][0])
        row=0;
    else if(target>matrix[m-1][0])
        row=m-1;
    int low=0,high=m-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(matrix[mid][n-1]>=target && target>=matrix[mid][0])
        {
            row=mid;
            break;
        }
        else if(matrix[mid][n-1]<target)
            low=mid+1;
        else
            high=mid-1;
    }
    if(row==-1)
        return false;
    
    low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(matrix[row][mid]==target)
            return true;
        else if(target<matrix[row][mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return false;
}
bool search1_sol2(vector<vector<int>> matrix,int target)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int low=0,high=n*m-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int row=mid/m;
        int col=mid%n;
        if(matrix[row][col] == target)
            return true;
        else if(matrix[row][col]<target)
            low=mid+1;
        else
            high=mid-1;
    }
    return false;
}
bool search2(vector<vector<int>> matrix,int target)
{
    int m=matrix.size();
    int n=matrix[0].size();
    int row=0,col=n-1;
    while(row<n && col>=0)
    {
        if(matrix[row][col]==target)
            return true;
        else if(matrix[row][col]>target)
            col--;
        else
            row++;
    }
    return false;
}
int main()
{
    int n1,n2;
    cout << "Enter the size of nums array: " ;
    cin >> n1 >> n2;
    vector<vector<int>> nums(n1,vector<int>(n2));
    cout << "Enter the elements of the nums1 array: " << endl;
    for(int i=0;i<n1;i++)
        for(int j=0;j<n2;j++)
            cin >> nums[i][j];

    int k;
    cout << "Enter the element to be searched: " << endl;
    cin >> k;
    if(search2(nums,k))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}