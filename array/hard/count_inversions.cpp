#include<bits/stdc++.h>
using namespace std;

/*
Q. count number of pairs arr[i]>arr[j] and i<j
*/

int merge(int arr[],int low,int mid, int high)
{
    int count=0;
    vector<int>temp;
    int left=low, right=mid+1;
    while(left<=mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            count+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
    return count;
}
int merge_sort(int arr[],int low,int high)
{
    int count=0;
    if(low<high)
    {
        int mid=(low+high)/2;
        count+=merge_sort(arr,low,mid);
        count+=merge_sort(arr,mid+1,high);
        count+=merge(arr,low,mid,high);
        return count;
    }
    else
        return count;
}
int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    int nums[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> nums[i];
    
    //BRUTE
    //TC-O(N^2)
    //SC-O(1)
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(nums[i]>nums[j])
                count++;
        }
    }
    cout << count << endl;

    //OPTIMAL
    //TC-O(N log N)
    //SC-O(N)
    cout << merge_sort(nums,0,n-1) << endl;

    return 0;
}