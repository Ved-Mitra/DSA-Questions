#include<bits/stdc++.h>
using namespace std;

void iteration (int arr[], int n)
{
    int smallest,index;
    for(int i=0;i<n-1;i++)
    {
        smallest=arr[i];
        index=i;
        for(int j=i;j<n;j++)
        {
            if(smallest>arr[j])
            {
                index=j;
                smallest=arr[j];
            }
        }
        int swap=arr[i];
        arr[i]=smallest;
        arr[index]=swap;
    }
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    return ;
}
void recursion (int arr[], int n,int i)
{
    if(i==n)
    {
        for(int j=0;j<n-1;j++)
            cout << arr[j] << " ";
        return;
    }
    int smallest=arr[i],index=i;
    for(int j=i;j<n;j++)
    {
        if(smallest>arr[j])
        {
            smallest=arr[j];
            index=j;
        }
    }
    int swap=arr[i];
    arr[i]=smallest;
    arr[index]=swap;
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