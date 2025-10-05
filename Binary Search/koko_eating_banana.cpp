#include<bits/stdc++.h>
using namespace std;

int total_hours(vector<int> &arr,int n,int k)
{
    int req_hour=0;
    for(int i=0;i<n;i++)
    {
        req_hour+=ceil((double)arr[i]/(double)k);
    }
    return req_hour;
}
int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> nums[i];
    cout << "Enter the number: ";
    int h;
    cin >> h;
    
    int largest=nums[0];
    for(int i=0;i<n;i++)
    {
        if(largest<nums[i])
            largest=nums[i];
    }
    int low=1,high=largest;
    int k=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int hour=total_hours(nums,n,mid);
        if(hour<=h)
        {
            k=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    cout << k << endl;
}
