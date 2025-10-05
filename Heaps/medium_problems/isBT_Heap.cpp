#include <bits/stdc++.h>
using namespace std;


bool isBinaryTreeHeap(vector<int> &arr)
{
    // arr is level order
    // need to check whether it is both CBT and a heap

    return isCBT(arr) && isHeap(arr,0);
    // we could also combine the function in to one using queue
}

bool isCBT(vector<int> &arr)
{
    //well no need to check as if array has no null marker then it is CBT array of CBT  tree
    int n=arr.size();
    bool null_found=false;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int m=q.size();
        for(int i=0;i<m;i++)
        {
            int index=q.front();
            q.pop();

            int left=2*index+1;
            int right=2*index+2;
            if(left>=n || right>=n)
            {
                if(null_found)
                    return false;
                null_found=true;
            }
            if(i<n)
            {
                q.push(left);
                q.push(right);
            }
        }
    }
    return true;
}

bool isHeap(vector<int> &arr,int i)
{
    int n=arr.size();
    if(i>=n)
        return true;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[i])
        return false;
    if(right<n && arr[right]>arr[i])
        return false;
    
    return isHeap(arr,left) && isHeap(arr,right);
}



int main()
{

}