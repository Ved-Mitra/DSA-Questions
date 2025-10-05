#include <bits/stdc++.h>
using namespace std;

vector<int> mergeHeap(vector<int> &a,vector<int> &b)
{
    vector<int> ans(a.size()+b.size());
    int i=0;
    for(;i<a.size();i++)
        ans[i]=a[i];
    for(;i<a.size()+b.size();i++)
        ans[i]=b[i-a.size()];
    
    int n=a.size()+b.size();

    for(int i=n/2-1;i>=0;i--)
        maxHeap(ans,i);
    return ans;
}

void maxHeap(vector<int> &arr,int i)
{
    int n=arr.size();
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;

    if(left<n && arr[left]>arr[largest])
        largest=left;
    if(right<n && arr[right]>arr[largest])
        largest=right;

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        maxHeap(arr,largest);
    }
}






int main()
{

}