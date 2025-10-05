#include <bits/stdc++.h>
using namespace std;

// Max-heapify: pushes arr[index] down to correct position
void MaxHeapify(vector<int> &arr, int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        MaxHeapify(arr, size, largest);
    }
}

// Convert min-heap to max-heap
void MinToMaxHeap(vector<int> arr)
{
    int n = arr.size();
    // Start from last internal node down to root
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        MaxHeapify(arr, n, i);
    }
}

int main()
{
    vector<int> minHeap = {1, 3, 5, 7, 9, 11}; // Example min-heap
    MinToMaxHeap(minHeap);

    for (int x : minHeap)
        cout << x << " ";
    cout << endl;
}