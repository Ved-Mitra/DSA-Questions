#include <bits/stdc++.h>
using namespace std;

vector<int> heapSort(vector<int> arr)
{
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--)
    {
        //constructing min Heap
        heapify_descending(arr, n, i);
    }

    while(n>0)
    {
        swap(arr[0],arr[n-1]);//swap is invitable as both element needs to be preserved
        n--;
        heapify_descending(arr,n,0);
    }
    return arr;
}

void heapify_descending(vector<int> &arr,int size,int i)
{
    if(i>=size)
        return;
    
    int x=arr[i]; //value to shift
    int index=i;
    while(true)
    {
        int left=2*index+1;
        int right=2*index+2;
        int smallest=-1;

        if(left<size && x>arr[left])
        {
            if(right<size && arr[right]<arr[left])
                smallest=right;
            else
                smallest=left;
        }
        else if(right<size && x>arr[right])
            smallest=right;
        
        if(smallest!=-1)
        {
            arr[index]=arr[smallest];
            index=smallest;
        }
        else
            break;
    }
    arr[index]=x;
}