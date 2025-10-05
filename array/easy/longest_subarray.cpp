#include<bits/stdc++.h>
using namespace std;
//longest subarray with sum k

void longest_subarray_positive_sum(int arr[], int n, long long k)
{
    //METHOD-1(BRUTE)
    //generating all subarray
    //TC-O(N^3)
    int len=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            for(int t=i;t<=j;t++)
            {
                sum+=arr[k];
            }
            if(sum==k)
            {
                len=max(len,j-i+1);
            }
        }
    }
    cout << len << endl;


    //METHOD-2(BRUTE)
    //TC-O(N^2)
    len=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(sum==k)
            {
                len=max(len,j-i+1);
            }
        }
    }
    cout << len << endl;


    //METHOD-3(BETTER)
    //TC-O(N log N)
    map<long long,int> preSumMap; //hash array
    long long sum=0;
    len=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==k)
        {
            len=max(len,i+1);
        }
        long long rem=sum-k;
        if(preSumMap.find(rem)!=preSumMap.end())
        {
            int length=i-preSumMap[rem];
            len=max(len,length);
        }
        if(preSumMap.find(sum)==preSumMap.end())//to prevent error by zeroes {2,0,0,3}
        {
            preSumMap[sum]=i;
        }
    }
    cout << len << endl;


    //METHOD-4(OPTIMAL) for positives only
    //two pointer approach
    //TC-O(N)
    //SC-O(1)
    len=0;
    int left=0,right=0;
    sum=arr[0];
    while(right<n)
    {
        while(sum>k && left<=right)
        {
            sum-=arr[left];
            left++;
        }
        if(sum==k)
        {
            len=max(len,right-left+1);
        }
        right++;
        if(right<n)
        {
            sum+=arr[right];
        }
    }
    return;
}
void longest_subarray_positive_negative_sum(int arr[], int n, long long k)
{
    map<long long,int> preSumMap; //hash array
    long long sum=0;
    int len=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==k)
        {
            len=max(len,i+1);
        }
        long long rem=sum-k;
        if(preSumMap.find(rem)!=preSumMap.end())
        {
            int length=i-preSumMap[rem];
            len=max(len,length);
        }
        if(preSumMap.find(sum)==preSumMap.end())//to prevent error by zeroes {2,0,0,3}
        {
            preSumMap[sum]=i;
        }
    }
    cout << len << endl;
    return;
}
int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    long long k;
    cout << "Enter the sum to be searched: ";
    cin >> k;
    longest_subarray_positive_sum(arr,n,k);
    //longest_subarray_positive_negative_sum(arr,n,k);
    return 0;
}