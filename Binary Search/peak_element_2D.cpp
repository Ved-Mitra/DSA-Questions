#include<bits/stdc++.h>
using namespace std;

/*
Q. return peak element in 2D array
*/
int findMaxIndex(vector<vector<int>> matrix,int n,int col)
{
    int MaxValue=-1;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(matrix[i][col] > MaxValue)
        {
            MaxValue=matrix[i][col];
            index=i;
        }
    }
    return index;
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

    int low=0,high=n1-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int maxRowIndex=findMaxIndex(nums,n1,mid);
        int left = mid-1 >= 0 ? nums[maxRowIndex][mid-1]:-1;
        int right = mid+1 < n1 ? nums[maxRowIndex][mid+1] : -1;
        if(nums[maxRowIndex][mid] > left && nums[maxRowIndex][mid] > right)
        {
            cout << maxRowIndex << mid << endl;
            break;
        }
        else if(nums[maxRowIndex][mid] < left)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout << -1 << "," << -1 << endl;

    return 0;
}