#include <bits/stdc++.h>
using namespace std;

//work of heapify is to take the node to it's corretc position

void MaxHeapify(vector<int> &arr,int size,int index)
{
    //maxHeap
    //TC-O(log n)
    //converts the nodes below index into a heap
    int largest=index;
    int leftChild=2*index+1;
    int rightChild=2*index+2;

    if(leftChild<size && arr[largest]<arr[leftChild])
        largest=leftChild;
    if(rightChild<size && arr[rightChild]>arr[largest])
        largest=rightChild;
    
    if(largest!=index)
    {
        swap(arr[largest],arr[index]);
        MaxHeapify(arr,size,largest);
    }
}

void MinHeapify(vector<int> &arr,int size,int index)
{
    //minHeap
    //TC-O(log n)
    //converts the nodes below index into a heap
    int smallest=index;
    int leftChild=2*index+1;
    int rightChild=2*index+2;

    if(leftChild<size && arr[smallest]>arr[leftChild])
        smallest=leftChild;
    if(rightChild<size && arr[rightChild]>arr[smallest])
        smallest=rightChild;
    
    if(smallest!=index)
    {
        swap(arr[smallest],arr[index]);
        MinHeapify(arr,size,smallest);
    }
}

int main()
{
    //convert an array into heap
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];

    //

    //vector<int> arr={-1,5,-2,5,56,48,89,-10};
    for(int i=n/2-1;i>=0;i--)
    {
        //TC-O(n)
        // heapify(arr,n,i);//heapify the array

        //starting from leaf ndoes n/2 to n
        //leaf nodes are heapified in itself
    }

    for(auto &x:arr)
        cout << x << " ";
}