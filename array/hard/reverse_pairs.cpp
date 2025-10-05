#include<bits/stdc++.h>
using namespace std;

/*
Q. return the number of reverse pairs nums[i]>2*nums[j] and i<j
*/
int count_pairs(int arr[],int low,int mid,int high)
{
    int count=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++)
    {
        while(right<=high && arr[i]>2*arr[right])
            right++;
        count+=(right-(mid+1));
    }
    return count;
}
void merge(int arr[],int low,int mid, int high)
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
}
int merge_sort(int arr[],int low,int high)
{
    int count=0;
    if(low<high)
    {
        int mid=(low+high)/2;
        count+=merge_sort(arr,low,mid);
        count+=merge_sort(arr,mid+1,high);
        count+=count_pairs(arr,low,mid,high);
        merge(arr,low,mid,high);
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
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(nums[i]>2*nums[j])
                count++;
        }
    }
    cout << count << endl;

    //OPTIMAL
    //TC-O(N log N)+O(N)
    cout << merge_sort(nums,0,n-1) << endl;

    return 0;
}