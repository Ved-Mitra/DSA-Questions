//Time complexity ---> O(N log2 N)
//Space complexity --> O(N)

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid, int high)
{
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

    //OLD CODE
    /*
    int n1=(left-mid+1), n2=(right-mid), i ,j ,k;
    int l[n1],r[n2];
    for(i=0;i<n1;i++)
        l[i]=arr[left+i];
    for(j=0;j<n2;j++)
        r[j]=arr[j+mid+1];
    i=j=0;
    k=left;
    while(i<n1 && j<n2)
    {
        if(l[i]<=r[j])
        {
            arr[k]=l[i];
            i++;
        }
        else
        {
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=r[j];
        j++;
        k++;
    }*/
}
void merge_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    else
        return;
}
int main()
{
    int n;
    cout << "Enter the size of array ";
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    merge_sort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout << arr[i] <<" ";
    return 0;
}