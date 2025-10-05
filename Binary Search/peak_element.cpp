#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> nums[i];


    if(n==1)
        return 0;
    int left=0,right=n-1;
    while(left<right)
    {
        int mid=(left+right)/2;
        if(nums[mid]<=nums[mid+1])
            left=mid+1;
        else
            right=mid;
    }
    cout << left << endl;


    //METHOD-2
    if(n==1)
        return 0;
    if(nums[0]>nums[1])
        return 0;
    if(nums[n-1]>nums[n-2])
        return n-1;
    left=1,right=n-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
        {
            cout << mid;
            break;
        }
        else if(nums[mid]>nums[mid+1])
            right=mid-1;
        else if(nums[mid]>nums[mid-1])
            left=mid+1;
    }
    
    return 0;
}