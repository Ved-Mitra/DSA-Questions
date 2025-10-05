#include <bits/stdc++.h>
using namespace std;

vector<int> heapSort(vector<int> arr)
{
    //considering arr = max heap
    //1. swap arr[0] with arr[n-1]
    //2. place root node to it's correct place

    int n=arr.size();
    for(int i=n/2-1;i>=0;i--)
    {
        //constructing max Heap
        heapify_ascending(arr, n, i);
    }

    while(n>0)
    {
        swap(arr[0],arr[n-1]);
        n--;
        heapify_ascending(arr,n,0);
    }
    return arr;
}

void heapify_ascending(vector<int> &arr,int size,int index)
{
    int leftChild=2*index+1;
    int rightChild=2*index+2;
    int largest=index;

    if(leftChild<size && arr[largest]<arr[leftChild])
        largest=leftChild;
    if(rightChild<size && arr[largest]<arr[rightChild])
        largest=rightChild;

    if(largest!=index)
    {
        swap(arr[largest],arr[index]);
        heapify_ascending(arr,size,largest);
    }
}



int main()
{

}