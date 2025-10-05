//Time complexity ---> O(N log N)
//Space complexity --> O(1)

#include<bits/stdc++.h>
using namespace std;

/*
THEORY
1. PICK A partition AND PLACE IT IN ITS CORRECT PLACE IN SORTED ARRAY, IT CAN BE
    (A)1st element in the array
    (B)last element of the array
    (C)median number of the array
    (D)random element of the array
2. SMALLER ON THE LEFT AND LARGER ON THE RIGHT
3.REPEAT THE ABOVE TWO STEPS
*/  

int partition(int arr[],int low,int high)
{
    int pivot=low;
    int i=low,j=high;
    while(i<j)
    {
        while(arr[i]<=arr[pivot] && i<=high-1)
            i++;
        while(arr[j]>arr[pivot] && j>=low+1)
            j--;
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[pivot],arr[j]);
    return j;
}
void quick_sort(int arr[],int low, int high)
{
    if(low<high)
    {
        int partition_index=partition(arr,low,high);
        quick_sort(arr,low,partition_index-1);
        quick_sort(arr,partition_index+1,high);
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
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    return 0;
}