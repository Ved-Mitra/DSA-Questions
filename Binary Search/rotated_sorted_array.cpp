#include<bits/stdc++.h>
using namespace std;


void part1(int arr[],int n,int x) //unique elements
{
    int left=0,right=n-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(arr[mid]==x)
        {
            cout << mid;
            break;
        }
        //left sorted
        if(arr[left]<=arr[mid])
        {
            if(arr[left]<=x && x<=arr[mid])
                right=mid-1;
            else
                left=mid+1;
        }
        //right sorted
        else
        {
            if(arr[mid]<=x && x<=arr[right])
                left=mid+1;
            else
                right=mid-1;
        }
    }
    cout << " not found" << endl;
}
void part2(int arr[],int n,int x)//duplicate elements
{
    int left=0,right=n-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(arr[mid]==x)
        {
            cout << "found";
            break;
        }
        if(arr[left]==arr[mid] && arr[mid]==arr[right])
        {
            left++;
            right--;
            continue;
        }
        //left sorted
        if(arr[left]<=arr[mid])
        {
            if(arr[left]<=x && x<=arr[mid])
                right=mid-1;
            else
                left=mid+1;
        }
        //right sorted
        else
        {
            if(arr[mid]<=x && x<=arr[right])
                left=mid+1;
            else
                right=mid-1;
        }
    }
    cout << " not found" << endl;
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