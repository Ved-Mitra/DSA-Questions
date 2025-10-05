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
    int x;
    cin >> x;
    
    //can use lower and upper bound
    vector<int>result(2);
    int left=0,right=n-1;
    int found=0;
    while(left<=right)//for leftmost
    {
        int mid = left + (right-left)/2;
        if(nums[mid]==x)
        {
            found=1;
            result[0]=mid;
            right=mid-1;
        }
        else if(nums[mid]<x)
            left=mid+1;
        else
            right=mid-1;
    }
    left=0;
    right=n-1;
    while(left<=right)//for rightmost
    {
        int mid = left + (right-left)/2;
        if(nums[mid]==x)
        {
            found=1;
            result[1]=mid;
            left=mid+1;
        }
        else if(nums[mid]<x)
            left=mid+1;
        else
            right=mid-1;
    }
    if(!found)
        result[0]=result[1]=-1;
    for(auto it:result)
        cout <<it <<" ";

}