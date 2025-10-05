#include<bits/stdc++.h>
using namespace std;
/*
Q. find the maximum sum in a subarray and also print subarray
*/
int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int max_sum=0;
    int subarray[2]={0};//stores the starting and ending index of subarray
    //BRUTE
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=arr[k];
            }
            if(max_sum<sum)
            {
                max_sum=sum;
                subarray[0]=i;
                subarray[1]=j;
            }
        }
    }
    for(int i=subarray[0];i<=subarray[1];i++)
        cout << arr[i];
    cout << "   " << max_sum << endl;

    //BETTER
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(max_sum<sum)
            {
                max_sum=sum;
                subarray[0]=i;
                subarray[1]=j;
            }
        }
    }
    for(int i=subarray[0];i<=subarray[1];i++)
        cout << arr[i];
    cout << "   " << max_sum << endl;

    //OPTIMAL
    //KADANE's ALGORITHM
    max_sum=INT_MIN;
    int sum=0;
    int start=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(max_sum<sum)
        {
            max_sum=sum;
            subarray[0]=start;
            subarray[1]=i;
        }
        if(sum==0)
            start=i;
        if(sum<0)
            sum=0;
    }
    for(int i=subarray[0];i<=subarray[1];i++)
        cout << arr[i];
    cout << "   " << max_sum << endl;

    return 0;
}