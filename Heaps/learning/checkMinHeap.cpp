#include <bits/stdc++.h>
using namespace std;

bool isValidMinHeap(vector<int> &arr,int index)
{
    if(index>=arr.size())
        return true;
    
    int leftChild=2*index+1;
    int rightChild=2*index+2;
    int n=arr.size();
    
    if(leftChild<n && arr[index]>arr[leftChild])
        return false;
    if(rightChild<n && arr[index]>arr[rightChild])
        return false;
    
    return isValidMinHeap(arr,leftChild) && isValidMinHeap(arr,rightChild);
}



int main()
{

}