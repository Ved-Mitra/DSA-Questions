/* 
arr[(i-1)/2]	Returns the parent node
arr[(2*i)+1]	Returns the left child node
arr[(2*i)+2]	Returns the right child node
*/

#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    public:
    vector<int> arr;
    int size;

    MinHeap()
    {
        size=0;
    }

    void insert(int x)
    {
        //TC-O(log n)
        arr.push_back(x);
        size++;
        int index=arr.size()-1;
        while(index > 0)
        {
            int parent = (index - 1) / 2;
            if(arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void pop(int x)
    {
        // always deleting the root node i.e. at index=0
        // 1. swap first node with the last node
        // 2. reomve last node
        // 3. propagate root node to it's correct position
        if (size == 0)
            return;
        swap(arr[0], arr[size - 1]);
        arr.pop_back();
        size--;
        int index = 0;
        while (true)
        {
            int leftIndex = 2 * index + 1;
            int rightIndex = 2 * index + 2;
            int smallest = index;

            if (leftIndex < size && arr[leftIndex] < arr[smallest])
                smallest = leftIndex;
            if (rightIndex < size && arr[rightIndex] < arr[smallest])
                smallest = rightIndex;

            if (smallest != index)
            {
                swap(arr[index], arr[smallest]);
                index = smallest;
            }
            else
            {
                break;
            }
        }
    }
};


int main()
{
    
}