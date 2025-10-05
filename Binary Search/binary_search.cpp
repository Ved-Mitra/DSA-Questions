#include<bits/stdc++.h>
using namespace std;


int lower_bound(int arr[],int n,int x)
{
    //lower_bound 
    //arr[index]>=x  x is given and index is smallest
    //if no such element than index = size of array
    int low=0,high=n-1;
    int ans=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>=x)
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    cout << ans << endl;
}
int high_bound(int arr[],int n,int x)
{
    //higher_bound 
    //arr[index]>x  x is given and index is smallest
    //if no such element than index = size of array
    int low=0,high=n-1;
    int ans=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>x)
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    cout << ans << endl;
}
int insert_position(int arr[],int n,int x)
{
    //tell the position of elemnet which is to be inserted
    int low=0,high=n-1;
    int ans=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>=x)
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    cout << ans << endl;
}
int floor_ceil(int arr[],int n,int x)
{
    //floor --> largest element in array <=x
    //ceil ---> smallest element in array >=x
    int ans=-1;
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]<=x)
        {
            ans=arr[mid];
            low=mid+1;
        }
        else
            high=mid-1;
    }
    cout << ans << endl;

    ans=-1;
    low=0;
    high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>=x)
        {
            ans=arr[mid];
            low=mid+1;
        }
        else
            high=mid-1;
    }
    cout << ans << endl;
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
    cout << "Enter the element: ";
    int x;
    cin >> x;
    



}