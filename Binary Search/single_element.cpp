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
        cout << nums[0];
    if(nums[0]!=nums[1])
        cout << nums[0];
    if(nums[n-1]!=nums[n-2])
        cout << nums[n-1];
    int left=1,right=n-2;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
        {
            cout << mid;
            break;
        }
        if((mid%2==1 && nums[mid-1]==nums[mid]) || (mid%2==0 && nums[mid]==nums[mid+1]))
            left=mid+1;
        else
            right=mid-1;
    }
    cout << -1;
    return 0;
}