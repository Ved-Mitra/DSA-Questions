#include<bits/stdc++.h>
using namespace std;

void iteration(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    return;
}
void recursion(int arr[],int n,int i)
{
    if(i==n)
    {
        for(int j=0;j<n;j++)
            cout << arr[j] << " ";
        return;
    }
    for(int j=0;j<n-i-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            int swap=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=swap;
        }
    }
    recursion(arr,n,i+1);
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
    iteration(arr,n);
    cout << endl;
    recursion(arr,n,0);
    return 0;
}