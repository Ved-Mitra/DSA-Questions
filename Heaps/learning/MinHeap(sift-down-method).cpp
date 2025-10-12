#include <bits/stdc++.h>
using namespace std;

class minHeap
{
    //by sift dowm method
    private:
        vector<int> arr;
        int size;

        void heapify(int i)
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
    public:
    minHeap()
    {

    }
    
    void insert(int x)
    {
        arr.push_back(x);
        size++;
        int i=size-1;
        while(true)
        {
            int parent=(i-1)/2;
            if(arr[parent]>x)
            {
                arr[i]=arr[parent];
                i=parent;
            }
            else
                break;
        }
        arr[i]=x;
    }
    void pop()
    {
        arr[0]=arr[size-1];
        arr.pop_back();
        size--;
        if(size>0)
            heapify(0);
    }

    int min()
    {
        if(size==0)
            return -1;
        return arr[0];
    }
};


int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {

    }
    

}