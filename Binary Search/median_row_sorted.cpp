#include<bits/stdc++.h>
using namespace std;

/*
Q. return median in 2d matrix n*m is odd (row-wise sorted)
*/
int element_smaller(vector<vector<int>> &mat,int k)
{
    int m=mat.size();
    int sum=0;
    for(int i=0;i<m;i++)
    {
        sum+=*upper_bound(mat[i].begin(),mat[i].end(),k);
    }
    return sum;
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

    int low=INT_MIN,high=INT_MAX;
    for(int i=0;i<n1;i++)
    {
        low=min(low,nums[i][0]);
        high=max(high,nums[i][n2-1]);
    }
    int req=(n1*n2)/2;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int smallEqual=element_smaller(nums,mid);
        if(smallEqual<=req)
            low=mid+1;
        else
            high=mid-1;
    }
    cout << low << endl;
    return 0;
}