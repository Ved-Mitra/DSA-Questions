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
    cout << "Enter the element: ";
    int target;
    cin >> target;
    
    int left=0,right=n-1;
    //METHOD-2
    if(right-left==1)
        return min(nums[left],nums[right]);
    while(right-left>1)
    {
        int mid=(left+right)/2;
        if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1])
            return nums[mid];
        if(nums[mid]<nums[right])
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    cout<<  min(nums[left],nums[right]) << endl;

    //METHOD-2
    left=0,right=n-1;
    int ans=INT_MAX;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(nums[left] <= nums[right])
        {
            ans=min(ans,nums[left]);
            break;
        }
        if(nums[left]<=nums[mid])
        {
            ans=min(ans,nums[left]);
            left=mid+1;
        }
        else
        {
            ans=min(ans,nums[mid]);
            right=mid-1;
        }
    }
    cout << ans << endl;

    return 0;
}