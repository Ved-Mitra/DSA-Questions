//always takes an element and places it in its current order
#include<bits/stdc++.h>
using namespace std;

/*
BEST CASE - O(N)
WORST CASE - O(N^2)
*/
void iteration (int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            int swap=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=swap;
            j--;
        }
    }
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    return;
}
void recursion (int arr[], int n, int i)
{
    if(i==n)
    {
        for(int j=0;j<n;j++)
            cout << arr[j] << " ";
        return ;
    }
    int j=i;
    while(j>0 && arr[j-1]>arr[j])
    {
        int swap=arr[j-1];
        arr[j-1]=arr[j];
        arr[j]=swap;
        j--;
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