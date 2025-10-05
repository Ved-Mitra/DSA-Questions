#include<bits/stdc++.h>
using namespace std;

/*
Q. Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
   Return the minimized largest sum of the split.
   A subarray is a contiguous part of the array
*/
int painters(vector<int> painter,int limit)
{
    int n=painter.size();
    int painters=1;
    int work=0;
    for(int i=0;i<n;i++)
    {
        if(work+painter[i]<=limit)
            work+=painter[i];
        else
        {
            painters++;
            work=painter[i];
        }
    }
    return painters;
}
int main()
{
    int n;
    cout << "Enter the size of numsay: " ;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the numsay: " << endl;
    for(int i=0;i<n;i++)
        cin >> nums[i];

    cout << " Enter the painters: ";
    int k;
    cin >> k;

    int low=*max_element(nums.begin(),nums.end());
    int high=accumulate(nums.begin(),nums.end(),0);
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(painters(nums,mid)<=k)
            high=mid-1;
        else
            low=mid+1;
    }
    cout << low << endl;
    return 0;
}