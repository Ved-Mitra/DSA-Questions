#include<bits/stdc++.h>
using namespace std;

/*
Q. return the row with max number of 1s
*/
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

    int cnt_max=0,index=-1;
    for(int i=0;i<n1;i++)
    {
        int cnt_ones=n2-*lower_bound(nums[i].begin(),nums[i].end(),1);
        if(cnt_ones>cnt_max)
        {
            cnt_max=cnt_ones;
            index=1;
        }
    }
}